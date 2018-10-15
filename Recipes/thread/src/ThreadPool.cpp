//
// Created by ning on 2018/10/12.
//

#include "ThreadPool.h"
#include "Except.h"

#include <boost/bind.hpp>
#include <assert.h>
#include <stdio.h>

using namespace Recipes;

ThreadPool::ThreadPool(const std::string &name) : mutex_(), cond_(mutex_), name_(name), running_(false) {}

ThreadPool::~ThreadPool() {
	if (running_)
		stop();
}

void ThreadPool::start(int numThreads) {
	assert(threads_.empty());
	running_ = true;
	threads_.reserve(numThreads);

	for (int i = 0; i < numThreads; ++i) {
		char id[32];
		snprintf(id, sizeof(id), "%d", i);  // what is doing????

		threads_.push_back(new Recipes::Thread(boost::bind(&ThreadPool::runInThread, this), name_ + id));
		threads_[i].start();
	}
}

void ThreadPool::stop() {
	running_ = false;
	cond_.notifyAll();

	// wrong
	for_each(threads_.begin(), threads_.end(), boost::bind(&Recipes::Thread::join, -1));
}

void ThreadPool::run(const Task &f) {
	if (threads_.empty()) {
		task();
	} else {
		MutexLockGuard lock(mutex_);
		queue_.push_back(f);
		cond_.notify();
	}
}

ThreadPool::Task ThreadPool::take() {
	MutexLockGuard lock(mutex_);
	while (queue_.empty() && running_) {
		cond_.wait();
	}

	Task task;
	if (!queue_.empty()) {
		task = queue_.front();
		queue_.pop_front();
	}
	return task;
}

void ThreadPool::runInThread() {
	try {
		while (running_) {
			Task task(take());
			if (task)
				task();
		}
	} catch (const Exception &ex) {
		fprintf(stderr, "exception caught in ThreadPool %s.\n", name_.c_str());
		fprintf(stderr, "reason: %s.\n", ex.what());
		abort();
	} catch (const std::exception &ex) {
		fprintf(stderr, "exception caught in ThreadPool %s.\n", name_.c_str());
		fprintf(stderr, "reason: %s.\n", ex.what());
		abort();
	} catch (...) {
		fprintf(stderr, "unknown exception caught in ThreadPool %s.\n", name_.c_str());
		abort();
	}
}
