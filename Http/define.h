//
// Created by ning on 2018/10/29.
//

#ifndef INTERVIEW_CPP_DEFINE_H
#define INTERVIEW_CPP_DEFINE_H

#pragma once

#include <string_view>

namespace Http {
	enum class content_type {
		string,
		multipart,
		urlencoded,
		octet_stream,
		websocket,
		unknown,
	};

	enum class res_content_type {
		html,
		json,
		string,
	};

	inline const std::string_view STAIC_RES = "staic_resource";
	inline const std::string CSESSIONID = "CSESSIONID";
}

#endif //INTERVIEW_CPP_DEFINE_H
