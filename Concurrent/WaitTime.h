//
// Created by ning on 2018/10/22.
//

#ifndef INTERVIEW_CPP_WAITTIME_H
#define INTERVIEW_CPP_WAITTIME_H

#include <ctime>
#include <chrono>
#include <future>
#include <iostream>
#include <condition_variable>
#include <mutex>
#include <list>

namespace Concurrent {

	void do_something() {
		for (int i = 0; i < 10000; ++i) {
			std::cout << "Ha, Hello Concurrent World." << std::endl;
		}
	}

	void some_Time() {
		std::clock();
		std::chrono::system_clock::now();   // some_clock::time_point 类型
		std::chrono::steady_clock::now();
		// 类型转换为 time_t

		// 时延 duration
		// std::chrono::duration;
		std::chrono::milliseconds ms(54802);
		std::chrono::seconds s = std::chrono::duration_cast<std::chrono::seconds>(ms); // 54s
		/*
		std::future<int> f = std::async(some_task);
		if (f.wait_for(std::chrono::milliseconds(35)) == std::future_status::ready)
			do_something_with(f.get());
		 */

		auto start = std::chrono::high_resolution_clock::now();
		do_something();
		auto stop = std::chrono::high_resolution_clock::now();

		//std::cout << "do_something() took " << std::chrono::duration<double, std::chrono::seconds>(stop - start).count()
		//         << " seconds" << std::endl;
	}

	std::condition_variable cv;
	bool done = false;
	std::mutex m_;

	bool wait_loop() {
		auto const timeout = std::chrono::steady_clock::now() + std::chrono::milliseconds(500);

		std::unique_lock<std::mutex> lock(m_);
		while (!done) {
			if (cv.wait_until(lock, timeout) == std::cv_status::timeout)
				break;
		}
		return done;
	}

	template<typename T>
	std::list<T> sequential_quick_sort(std::list<T> input) {
		if (input.empty())
			return input;

		std::list<T> result;
		result.splice(result.begin(), input, input.begin()); // 1

		T const &pivot = *result.begin(); // 2

		auto divide_point = std::partition(input.begin(), input.end(), [&](T const &t) { return t < pivot; }); // 3

		std::list<T> lower_part;
		lower_part.splice(lower_part.end(), input, input.begin(), divide_point); // 4

		auto new_lower(sequential_quick_sort(std::move(lower_part))); // 5
		auto new_higher(sequential_quick_sort(std::move(input))); // 6

		result.splice(result.end(), new_higher); // 7
		result.splice(result.begin(), new_lower); // 8
		return result;
	}

	template<typename T>
	std::list<T> parallel_quick_sort(std::list<T> input) {
		if (input.empty())
			return input;

		std::list<T> result;
		result.splice(result.begin(), input, input.begin());

		T const &pivot = *result.begin();

		auto divide_point = std::partition(input.begin(), input.end(), [&](T const &t) { return t < pivot; });

		std::list<T> lower_part;
		lower_part.splice(lower_part.end(), input, input.begin(), divide_point);

		// 1 --> another thread
		std::future<std::list<T>> new_lower(std::async(&parallel_quick_sort<T>, std::move(lower_part)));
		// 2 --> current thread
		auto new_higher(parallel_quick_sort(std::move(input)));

		result.splice(result.end(), new_higher); // 3
		result.splice(result.begin(), new_lower.get()); // 4
		return result;
	}

	/*
	 * template<typename F, typename A>
   std::future<std::result_of<F(A &&)>::type> spawn_task(F &&f, A &&a) {
	   typedef std::result_of<F(A &&)>::type result_type;

	   std::packaged_task<result_type(A &&)> task(std::move(f));
	   std::future<result_type> res(task.get_future());
	   std::thread t(std::move(task), std::move(a));
	   t.detach();
	   return res;
   }
	*/
}

/*
 * namespace Concurrent {
	struct card_inserted {
		std::string account;
	};

	class atm {
	public:
		void run() {
			state = &atm::waiting_for_card;
			try {
				for (;;)
					(this->*state)(); // 7
			} catch (messaging::close_queue const &) {

			}
		}

	private:
		void (atm::*state)();

		void waiting_for_card() {
			interface_hardware.send(display_enter_card());
			//
			incoming.wait().handle<card_inserted>([&](card_inserted &msg) {
				account = msg.account;
				pin = "";
				interface_hardware.send(display_enter_pin());
				state = &atm::getting_pin;
			});
		}

		void getting_pin();

		void verifying_pin() {}

		void done_processing() {}

		std::string account;
		std::string pin;

		messaging::receiver incoming;
		messaging::sender bank;
		messaging::sender interface_hardware;
	};

	void atm::getting_pin() {
		incoming.wait().handle<digit_pressed>([&](digit_pressed const &msg) {
			unsigned const pin_length = 4;
			pin += msg.digit;
			if (pin.length() == pin_length) {
				bank.send(verify_pin(account, pin, incoming));
				state = &atm::verifying_pin;
			}
		}).handle<clear_last_pressed>([&](clear_last_pressed const &msg) {
			if (!pin.empty())
				pin.resize(pin.length() - 1);
		}).handle<cancel_pressed>([&](cancel_pressed const &msg) {
			state = &atm::done_processing;
		});
	}
}*/
#endif //INTERVIEW_CPP_WAITTIME_H
