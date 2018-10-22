//
// Created by ning on 2018/10/22.
//

#ifndef INTERVIEW_CPP_ONE_OFF_EVENT_H
#define INTERVIEW_CPP_ONE_OFF_EVENT_H

#include <future>
#include <iostream>
#include <deque>
#include <mutex>
#include <thread>
#include <utility>
#include <math.h>

namespace Concurrent {
	struct X {
		void foo(int i, std::string const &str) {
			std::cout << i << " " << str << std::endl;
		}

		std::string bar(std::string const &str) {
			std::cout << str << std::endl;
			return str;
		}
	};

	struct Y {
		double operator()(double d) {
			std::cout << d << std::endl;
			return d;
		}
	};

	class move_only {
	public:
		move_only() = default;

		move_only(move_only &&) {}

		move_only(move_only const &) = delete;

		move_only &operator=(move_only &&) {}

		move_only &operator=(move_only const &) = delete;

		void operator()() {}
	};

	X baz(X &x) {
		return x;
	}

	void test_oneOffEvent1() {
		X x;
		auto f1 = std::async(&X::foo, &x, 42, "hello"); // p = &x; p->foo(...);
		auto f2 = std::async(&X::bar, x, "goodbye");   // 调用 tmpx.bar("goodbye"), 拷贝副本

		Y y;
		// auto f3 = std::async(Y(), 3, 141);      // 调用 tmpy(3.141)
		auto f4 = std::async(std::ref(y), 2.78);   // 调用y(2.78)

		std::async(baz, std::ref(x));   // 调用 baz(x)

		auto f5 = std::async(move_only());  // 调用tmp() -> 由 std::move(move_only())构造

		// 在新线程上执行
		auto f6 = std::async(std::launch::async, Y(), 1.2);

		// 在 wait() 或 get() 调用时执行
		auto f7 = std::async(std::launch::deferred, baz, std::ref(x));

		// 选择实现方式
		auto f8 = std::async(std::launch::deferred | std::launch::async, baz, std::ref(x));
		auto f9 = std::async(baz, std::ref(x));
		f7.wait();  // 调用延迟函数
	}

}

namespace Concurrent {
	// task and future
	template<typename Callable>
	class packaged_tasked<std::string(std::vector<char> *, int)> {
	public:
		template<typename Callable>
		explicit packaged_tasked(Callable &&f);

		std::future<std::string> get_future();

		void operator()(std::vector<char> *, int);
	};

	std::mutex m;
	std::deque<std::packaged_task<void()>> tasks;

	bool gui_shutdown_message_received() {
		std::cout << "Received the shutdown message." << std::endl;
	}

	void get_and_process_gui_message() {
		if (gui_shutdown_message_received())
			std::cout << "Processing the received message." << std::endl;
	}

	void gui_thread() {     // 1
		while (!gui_shutdown_message_received()) {  // 2  轮询
			get_and_process_gui_message();  // 3
			std::packaged_task<void()> task;
			{
				std::lock_guard<std::mutex> lock(m);
				if (tasks.empty())  // 4    无任务
					continue;
				task = std::move(tasks.front()); // 5 队列中提取一个任务，并执行
				tasks.pop_front();
			}
			task();     // 6 执行
		}
	}

	std::thread gui_bg_thread(gui_thread);

	template<typename Func>
	std::future<void> post_task_for_gui_thread(Func f) {    // 将任务传进任务队列中
		std::packaged_task<void()> task(f);     // 7 任务打包
		std::future<void> res = task.get_future();      // 8 获取 future 对象
		std::lock_guard<std::mutex> lock(m);        // 9 上锁
		tasks.push_back(std::move(task));       // 10 放入任务队列
		return res;
	}

	// std::promise
	/*
	class connection_set {
	};

	void process_connections(connection_set &connections) {
		while (!done(connections)) {    // 1 依次检查每一个连接
			for (connection_iteratir connection = connections.begin(), end_ = connections.end();
			     connection != end_; ++connection) {    // 2

				if (connection->has_incoming_data()) {  // 3 接受数据
					data_packet data = connection->incoming();

					// 4 将一个 ID 映射到一个 std::promise，并且值是设置在包的有效负载中
					std::promise<payload_type> &p = connection->get_promise(data.id);
					p.set_value(data.payload);
				}

				if (connection->has_outgoing_data()) {// 5 发送数据
					outgoing_packet data = connection->top_of_outgoing_queue();
					connection->send(data);
					data.promise.set_value(true);    // 6
				}
			}
		}
	}
	*/

	// std::future and exception
	double square_root(double x) {
		if (x < 0)
			throw std::out_of_range("x < 0");
		return sqrt(x);
	}

/*
std::future<double> f = std::async(square_root, -1); // exception in std::future<double> object
double y = f.get();

std::promise<double> some_promise;

try{
	some_promise.set_value(calculate_value());
} catch(...){
	some_promise.set_exception(std::current_exception());
    some_promise.set_exception(std::copy_current_exception(std::logic_error("foo")));
}
*/
/*
	std::promise<int> p;
	std::future<int> f(p.get_future());

	assert(f.valid());
	std::shared_future<int> sf(std::move(f));
	assert(!f.valid());
	assert(sf.valid());
*/
}

#endif //INTERVIEW_CPP_ONE_OFF_EVENT_H
