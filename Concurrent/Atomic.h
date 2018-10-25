//
// Created by ning on 2018/10/23.
//

#ifndef INTERVIEW_CPP_ATOMIC_H
#define INTERVIEW_CPP_ATOMIC_H

#include <mutex>
#include <iostream>
#include <atomic>
#include <thread>

namespace Concurrent {
	// 实现自旋互斥锁      std::atomic_flag
	class spinlock_mutex {
	public:
		spinlock_mutex() : flag(ATOMIC_FLAG_INIT) {}

		void lock() {

			// Read-modify-write
			while (flag.test_and_set(std::memory_order_acquire));
		}

		void unlock() {
			flag.clear(std::memory_order_release);
		}

	private:
		std::atomic_flag flag;
	};

	std::atomic<bool> x, y;
	std::atomic<int> z;

	void write_x() {
		x.store(true, std::memory_order_seq_cst);
	}

	void write_y() {
		y.store(true, std::memory_order_seq_cst);
	}

	void read_x_then_y() {
		while (!x.load(std::memory_order_seq_cst));
		if (y.load(std::memory_order_seq_cst))  // 3
			++z;
	}

	void read_y_then_x() {
		while (!y.load(std::memory_order_seq_cst));
		if (x.load(std::memory_order_seq_cst))      // 4
			++z;
	}

	void test_atomic() {
		x = false, y = false;
		z = 0;

		std::thread a(write_x);
		std::thread b(write_y);
		std::thread c(read_x_then_y);
		std::thread d(read_y_then_x);
		a.join();
		b.join();
		c.join();
		d.join();
		assert(z.load() != 0);
	}
}

#endif //INTERVIEW_CPP_ATOMIC_H
