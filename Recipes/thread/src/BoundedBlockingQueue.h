//
// Created by ning on 2018/10/12.
//

#ifndef INTERVIEW_CPP_BOUNDEDBLOCKINGQUEUE_H
#define INTERVIEW_CPP_BOUNDEDBLOCKINGQUEUE_H

#include "Condition.h"
#include "Mutex.h"

#include <boost/noncopyable.hpp>
#include <assert.h>
#include <boost/circular_buffer.hpp>

namespace Recipes {
	template<typename T>
	class BoundedBlockingQueue : boost::noncopyable {
	public:
		explicit BoundedBlockingQueue(int maxSize) : mutex_(), notEmpty_(mutex_), notFull_(mutex_), queue_(maxSize) {}

		void put(const T &x) {
			MutexLockGuard lock(mutex_);

			while (queue_.full())
				notFull_.wait();

			assert(!queue_.full());
			queue_.push_back(x);
			notEmpty_.notify();
		}

		T take() {
			MutexLockGuard lock(mutex_);
			while (queue_.empty())
				notEmpty_.wait();
			assert(!queue_.empty());

			T front(queue_.front());
			queue_.pop_front();
			notFull_.notify();
			return front;
		}

		bool empty() const {
			MutexLockGuard lock(mutex_);
			return queue_.empty();
		}

		bool full() const {
			MutexLockGuard lock(mutex_);
			return queue_.full();
		}

		size_t size() const {
			MutexLockGuard lock(mutex_);
			return
		}

	private:
		mutable MutexLock mutex_;
		Condition notEmpty_;
		Condition notFull_;
		boost::circular_buffer<T> queue_;
	};
}


#endif //INTERVIEW_CPP_BOUNDEDBLOCKINGQUEUE_H
