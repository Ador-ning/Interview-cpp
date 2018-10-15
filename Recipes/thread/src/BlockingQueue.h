//
// Created by ning on 2018/10/11.
//

#ifndef INTERVIEW_CPP_BLOCKINGQUEUE_H
#define INTERVIEW_CPP_BLOCKINGQUEUE_H

#include <boost/noncopyable.hpp>
#include <deque>
#include <assert.h>

#include "Mutex.h"
#include "Condition.h"

namespace Recipes {
	template<typename T>
	class BlockingQueue : boost::noncopyable {
	public:
		BlockingQueue() : mutex_(), notEmpty_(mutex_), queue_() {}

		void put(const T &x) {
			MutexLockGuard lock(mutex_);
			queue_.push_back(x);
			notEmpty_.notify();
		}

		T take() {
			MutexLockGuard lock(mutex_);

			while (queue_.empty())
				notEmpty_.notify();

			assert(!queue_.empty());
			T front(queue_.front());
			queue_.pop_front();
			return front;
		}

		size_t size() const {
			MutexLockGuard lock(mutex_);
			return queue_.size();
		}

	private:
		mutable MutexLock mutex_;
		Condition notEmpty_;
		std::deque<T> queue_;
	};
}
#endif //INTERVIEW_CPP_BLOCKINGQUEUE_H
