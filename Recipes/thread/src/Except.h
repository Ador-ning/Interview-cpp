
#ifndef INTERVIEW_CPP_EXCEPT_H
#define INTERVIEW_CPP_EXCEPT_H

#include <string>
#include <exception>

namespace Recipes {
	class Exception : public std::exception {
	public:
		explicit Exception(const char *what);

		virtual ~Exception() throw();

		virtual const char *what() const throw();

		const char *stackTrace() const throw();

	private:
		std::string message_t;
		std::string stack_;
	};
}
#endif //INTERVIEW_CPP_EXCEPT_H
