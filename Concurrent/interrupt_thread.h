//
// Created by ning on 2018/10/29.
//

#ifndef INTERVIEW_CPP_INTERRUPT_THREAD_H
#define INTERVIEW_CPP_INTERRUPT_THREAD_H

namespace Concurrent {
	// 1. 启动和中断线程
	class interrupt_flag {
	public:
		interrupt_flag() : thread_cond(0) {}

		void set() {
			flag.store(true, std::memory_order_relaxed);
			std::lock_guard<std::mutex> lock(set_clear_mutex);
			if (thread_cond)
				thread_cond->notify_all();
		}

		bool is_set() const {
			return flag.load(std::memory_order_relaxed);
		}

		void set_condition_variable(std::condition_variable &cv) {
			std::lock_guard<std::mutex> lock(set_clear_mutex);
			thread_cond = &cv;
		}

		void clear_condition_variable() {
			std::lock_guard<std::mutex> lock(set_clear_mutex);
			thread_cond = 0;
		}

		struct clear_cv_on_destruct {
			~clear_cv_on_destruct() {
			}
		};

	private:
		std::atomic<bool> flag;
		std::condition_variable *thread_cond;
		std::mutex set_clear_mutex;
	};

	thread_local interrupt_flag this_thread_interrupt_flag; // 1

	void interruption_point() {
		if (this_thread_interrupt_flag.is_set())
			throw;  // 中断异常类处理
	}

	void interrupt_wait(std::condition_variable &cv, std::unique_lock<std::mutex> &lock) {
		this_thread_interrupt_flag.set_condition_variable(cv);
		interruption_point();
		this_thread_interrupt_flag.set_condition_variable(cv);
		this_thread_interrupt_flag.clear_condition_variable();

		interruption_point();
		cv.wait_for(lock, std::chrono::milliseconds(1));
		interruption_point();
	}

	class interrupt_thread {
	public:
		template<typename FunctionType>
		interrupt_thread(FunctionType f) {
			std::promise<interrupt_flag *> p;   // 2
			internal_thread = std::thread([f, &p] {
				p.set_value(&this_thread_interrupt_flag);
				f();    // 4
			});
			flag = p.get_future().get();    // 5
		}

		void join();

		void detach();

		bool joinable();

		void interrupt() {
			if (flag)
				flag->set();    // 6
		}

	private:
		std::thread internal_thread;
		interrupt_flag *flag;
	};
}

#endif //INTERVIEW_CPP_INTERRUPT_THREAD_H
