//
// Created by ning on 2018/11/1.
//

#ifndef INTERVIEW_CPP_MIME_TYPES_H
#define INTERVIEW_CPP_MIME_TYPES_H

#include <string>

namespace http {
	namespace mime_types {
		std::string extension_to_type(const std::string &extension);
	}
}

#endif //INTERVIEW_CPP_MIME_TYPES_H
