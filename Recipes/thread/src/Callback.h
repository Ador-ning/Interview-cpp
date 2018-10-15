//
// Created by ning on 2018/10/12.
//

#ifndef INTERVIEW_CPP_CALLBACK_H
#define INTERVIEW_CPP_CALLBACK_H

#include <functional>
#include <memory>

namespace Recipes {
	template<typename CLASS, typename... ARGS>
	class Callback {
	public:
		Callback(const std::weak_ptr<CLASS> &object,
		         const std::function<void(CLASS *, ARGS...)> &function) : object_(object), function_(function) {}

		// Default dtor, copy ctor and assignment

		void operator()(ARGS &&... args) const {
			std::shared_ptr<CLASS> ptr(object_.lock());
			if (ptr)
				function_(ptr.get(), std::forward<ARGS>(args)...);
		}

	private:
		std::weak_ptr<CLASS> object_;
		std::function<void(CLASS *, ARGS...)> function_;
	};

	template<typename CLASS, typename...ARGS>
	Callback<CLASS, ARGS...> makeCallback(const std::shared_ptr<CLASS> &object,
	                                      void(CLASS::*function)(ARGS...)) {
		return Callback<CLASS, ARGS...>(object, function);
	}

	template<typename CLASS, typename...ARGS>
	Callback<CLASS, ARGS...> makeCallback(const std::shared_ptr<CLASS> &object,
	                                      void(CLASS::*function)(ARGS...) const) {
		return Callback<CLASS, ARGS...>(object, function);
	}
}
#endif //INTERVIEW_CPP_CALLBACK_H
