//
// Created by ning on 2018/10/11.
//

#ifndef INTERVIEW_CPP_MUTEX_H
#define INTERVIEW_CPP_MUTEX_H

#include <assert.h>
#include <pthread.h>
#include <boost/noncopyable.hpp>

#include "Thread.h"

namespace Recipes {
	class MutexLock : boost::noncopyable {
	public:
		MutexLock() : holder_(0) {
			pthread_mutex_init(&mutex_, NULL);
		}

		~MutexLock() {
			assert(holder_ == 0);
			pthread_mutex_destroy(&mutex_);
		}

		bool isLockedByThisThread() {
			return holder_ == CurrentThread::tid();
		}

		void assertLocked() {
			assert(!isLockedByThisThread());
		}

		void lock() {
			pthread_mutex_lock(&mutex_);
			holder_ = CurrentThread::tid();
		}

		void unlock() {
			holder_ = 0;
			pthread_mutex_unlock(&mutex_);
		}

		pthread_mutex_t *getPthreadMutex() {
			return &mutex_;  // non-const
		}

	private:
		pthread_mutex_t mutex_;
		pid_t holder_;
	};

	class MutexLockGuard : boost::noncopyable {
	public:
		explicit MutexLockGuard(MutexLock &mutex) : mutex_(mutex) {
			mutex_.lock();
		}

		~MutexLockGuard() {
			mutex_.unlock();
		}

	private:
		MutexLock &mutex_;
	};

#define MutexLockGuard(x) error "Missing guard object name"
}
#endif //INTERVIEW_CPP_MUTEX_H
