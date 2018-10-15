//
// Created by ning on 2018/10/11.
//

#ifndef INTERVIEW_CPP_THREADPOOL_H
#define INTERVIEW_CPP_THREADPOOL_H

#include "Mutex.h"
#include "Condition.h"
#include "Thread.h"

#include <boost/noncopyable.hpp>
#include <boost/function.hpp>
#include <boost/ptr_container/ptr_vector.hpp>

#include <deque>

namespace Recipes {
	class ThreadPool : boost::noncopyable {
	public:
		typedef boost::function<void()> Task;

		explicit ThreadPool(const std::string &name = std::string());

		~ThreadPool();

		void start(int numThreads);

		void stop();

		void run(const Task &f);

	private:
		void runInThread();

		Task take();

		MutexLock mutex_;
		Condition cond_;
		std::string name_;
		boost::ptr_vector<Recipes::Thread> threads_;
		std::deque<Task> queue_;
		bool running_;
	};
}

#endif //INTERVIEW_CPP_THREADPOOL_H
