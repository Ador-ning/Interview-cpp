//
// Created by ning on 2018/10/12.
//

#ifndef INTERVIEW_CPP_THREADLOCALSINGLETON_H
#define INTERVIEW_CPP_THREADLOCALSINGLETON_H

#include <boost/noncopyable.hpp>

namespace Recipes {
	template<typename T>
	class ThreadLocalSingleton : boost::noncopyable {
	public:
		static T &instance() {
			if (!t_value_) {
				t_value_ = new T();
			}
			return *t_value_;
		}

		static void destroy() {
			delete t_value_;
			t_value_ = 0;
		}

	private:
		ThreadLocalSingleton();

		~ThreadLocalSingleton();

		static __thread T *t_value_;
	};

	// questions
	template<typename T>
	__thread T *ThreadLocalSingleton<T>::t_value_ = 0;
}

#endif //INTERVIEW_CPP_THREADLOCALSINGLETON_H
