//
// Created by ning on 2018/10/15.
//

#ifndef INTERVIEW_CPP_THREAD_TEST_H
#define INTERVIEW_CPP_THREAD_TEST_H

#include <thread>
#include <iostream>

namespace Concurrent {
	void do_something(int i) {
		std::cout << "do something: ";
		std::cout << i << std::endl;
	}

	void do_something_in_current_thread() {
		std::cout << "do something in current thread." << std::endl;
	}

	class background_task {
	public:
		background_task(int &i_) : i(i_) {}

		void operator()() const { // operator ovveride
			for (unsigned j = 0; j < 100; ++j) {
				do_something(j++);
			}
		}

	private:
		int &i;
	};

	class thread_guard {
		std::thread &t;
	public:
		explicit thread_guard(std::thread &t_) : t(t_) {}

		~thread_guard() {
			if (t.joinable())
				t.join();
		}

		thread_guard(thread_guard const &) = delete;

		thread_guard &operator=(thread_guard const &) = delete;
	};

	void some_function() {
		std::cout << "Some function." << std::endl;
	}

	void some_other_function() {
		std::cout << "Some other function." << std::endl;
	}

	void test_thread() {
		std::thread t1(some_function);    // comment1:
		std::thread t2 = std::move(t1);    // comment2:
		t1 = std::thread(some_other_function);    // comment3:
		std::thread t3;        // comment4:
		t3 = std::move(t2);        // comment5:
		// t1 = std::move(t3);        // comment6:
	}
}
#endif //INTERVIEW_CPP_THREAD_TEST_H
