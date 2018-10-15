//
// Created by ning on 2018/10/11.
//

#include "Thread.h"

#include <boost/weak_ptr.hpp>
#include <unistd.h>

// #include <sys/prctl.h>   linux，not using in MacOS
#include <sys/syscall.h>
#include <sys/types.h>

namespace Recipes {
	namespace CurrentThread {
		__thread const char *t_threadName = "Unknown";
	}
}

namespace Recipes {
	__thread pid_t t_cachedTid = 0;

	pid_t gettid() {
		return static_cast<pid_t > (::syscall(SYS_gettid));
	}

	void afterFork() {
		t_cachedTid = gettid();
		Recipes::CurrentThread::t_threadName = "main";
	}

	class ThreadNameInitializer {
	public:
		ThreadNameInitializer() {
			Recipes::CurrentThread::t_threadName = "main";
			pthread_atfork(NULL, NULL, &afterFork);
		}
	};

	ThreadNameInitializer init;

	struct ThreadData {
		typedef Recipes::Thread::ThreadFunc ThreadFunc;

		ThreadFunc func_;
		std::string name_;
		boost::weak_ptr<pid_t> wkTid_;

		ThreadData(const ThreadFunc &func, const std::string &name, const boost::shared_ptr<pid_t> &tid) : func_(func),
		                                                                                                   name_(name),
		                                                                                                   wkTid_(tid) {

		}

		void runInThread() {
			pid_t tid = Recipes::CurrentThread::tid();
			boost::shared_ptr<pid_t> ptid = wkTid_.lock();

			if (ptid) {
				*ptid = tid;
				ptid.reset();
			}

			Recipes::CurrentThread::t_threadName = name_.empty() ? "recipesThread" : name_.c_str();

			// Linux change Thread name
			// ::prctl(PR_SET_NAME, muduo::CurrentThread::t_threadName);

			func_();
			Recipes::CurrentThread::t_threadName = "finished";
		}
	};

	void *startThread(void *obj) {
		auto *data = static_cast<ThreadData *>(obj);
		data->runInThread();
		delete data;
		return NULL;
	}
}

using namespace Recipes;

pid_t CurrentThread::tid() {
	if (t_cachedTid == 0) {
		t_cachedTid = gettid();
	}
	return t_cachedTid;
}

const char *CurrentThread::name() {
	return t_threadName;
}

bool CurrentThread::isMainThread() {
	return tid() == ::gettid();
}

AtomicInt32 Thread::numCreated_;

void Thread::start() {
	assert(!started_);
	started_ = true;

	ThreadData *data = new ThreadData(func_, name_, tid_);

	if (pthread_create(&pthreadId_, NULL, &startThread, data)) {
		started_ = false;
		delete data;
		abort();
	}
}

void Thread::join() {
	assert(started_);
	assert(!joined_);

	joined_ = true;
	pthread_join(pthreadId_, NULL);
}