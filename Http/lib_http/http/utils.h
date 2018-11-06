//
// Created by ning on 2018/11/1.
//

#ifndef INTERVIEW_CPP_UTILS_H
#define INTERVIEW_CPP_UTILS_H

#include "./response.h"
#include "./request.h"

#include <boost/algorithm/string/trim.hpp>
#include <string>

namespace http {
	bool iequal(const char *src, std::size_t src_len, const char *dst, std::size_t dst_Len);

	std::string http_date(time_t t);

	char *http_date(char *res, time_t t);

	response reply_static_file(std::string const &static_path, request const &req);

	std::size_t base64_encode(char *_dst, const void *_src, std::size_t len, int url_encoded);

	bool is_valid_utf8(unsigned char *s, std::size_t length);

	// int convert to hex string
	template<typename T>
	void integral_to_hex_str(T n, char *s) {
		static_assert(std::is_integral<T>::value, "Parameter n must be integral.");
		const char hex_lookup[] = "0123456789abcdef";
		int len = 0;

		if (n == 0)
			len = 1;

		for (auto tmp = n; tmp != 0; tmp >>= 4) {
			++len;
		}
		s[len] = '\0';

		for (--len; len >= 0; n >>= 4, --len) {
			s[len] = hex_lookup[n & 0xf];
		}
	}

	inline int htoi(int c1, int c2) {
		int value;
		int c;

		c = c1;
		if (isupper(c)) // upper to lower
			c = tolower(c);

		value = ((c >= '0' && c <= '9') ? c - '0' : c - 'a' + 10) * 16;

		c = c2;
		if (isupper(c))
			c = tolower(c);
		value += (c >= '0' && c <= '9') ? c - '0' : c - 'a' + 10;

		return value;
	}

	template<typename IteratorT, typename MapT>
	void kv_parser(IteratorT begin, IteratorT end, MapT &result, int kv_sep, int filed_sep, bool unescape, bool trim) {
		std::string key, val;

		auto result_add = [&result, trim](std::string key, std::string val) {
			if (trim) {
				boost::algorithm::trim(key);
				boost::algorithm::trim(val);
			}
			result.emplace(key, val); //
		};

		bool is_k = true;
		for (auto it = begin; it != end; ++it) {
			char c = *it;

			if (c == filed_sep) {
				is_k = true;
				result_add(key, val); //
			} else if (c == kv_sep) {
				is_k = false;
				val.clear();
			} else {
				if (unescape && c == '%') {
					++it;
					char c1 = *it;
					++it;
					char c2 = *it;
					c = htoi(c1, c2);
				}

				if (is_k)
					key.push_back(c);
				else
					val.push_back(c);
			}
		}

		if (!is_k)
			result_add(key, val); // what using???
	}
}

#endif //INTERVIEW_CPP_UTILS_H
