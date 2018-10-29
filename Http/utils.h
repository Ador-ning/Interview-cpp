//
// Created by ning on 2018/10/29.
//

#ifndef INTERVIEW_CPP_UTILS_H
#define INTERVIEW_CPP_UTILS_H

#pragma once

#include <string>
#include <sstream>
#include <iomanip>
#include <cstddef>
#include <string_view>  // point
#include <cstdlib>
#include <map>
#include <vector>
#include <algorithm>
#include <type_traits>  // point
#include <cctype>
#include <istream>
#include "define.h"

namespace Http {
	class noncopyable {
	public:
		noncopyable() = default;

		~noncopyable() = default;

	private:
		noncopyable(const noncopyable &) = delete;

		noncopyable &operator=(const noncopyable &)= delete;
	};

	// string / string_view function object
	struct ci_less {
		// case-independent compare_less binary function
		struct nocase_compare {
			bool operator()(const unsigned char &c1, const unsigned char &c2) const {
				return tolower(c1) < tolower(c2);
			}

		};

		bool operator()(const std::string &s1, const std::string &s2) const {
			return std::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(), nocase_compare());
		}

		bool operator()(std::string_view s1, std::string_view s2) const {
			return std::lexicographical_compare(s1.begin(), s1.end(),
			                                    s2.begin(), s2.end(), nocase_compare());
		}
	};

	// char_traits
	template<class T>
	struct sv_char_trait : std::char_traits<T> {
		using base_t = std::char_traits<T>;
		using char_type = typename base_t::char_type;

		static constexpr int compare(std::string_view s1, std::string_view s2) noexcept {
			if (s1.length() != s2.length())
				return -1;

			size_t n = s1.length();
			for (size_t i = 0; i < n; ++i) {
				if (!base_t::eq(s1[i], s2[i]))
					return base_t::eq(s1[i], s2[i]) ? -1 : 1;
			}
			return 0;
		}

		static constexpr size_t find(std::string_view str, const char_type &a) noexcept {
			auto s = str.data();
			for (size_t i = 0; i < str.length(); ++i) {
				if (base_t::eq(s[i], a))
					return i;
			}
			return std::string_view::npos;
		}
	};

	inline std::string_view trim_left(std::string_view v) {
		v.remove_prefix((std::min)(v.find_first_not_of(" "), v.size()));
		return v;
	}

	inline std::string_view trim_right(std::string_view v) {
		v.remove_suffix((std::min)(v.size() - 1 - v.find_first_not_of(" "), v.size()));
		return v;
	}

	inline std::string_view trim(std::string_view v) {
		v.remove_prefix((std::min)(v.find_first_not_of(" "), v.size()));
		v.remove_suffix((std::min)(v.size() - 1 - v.find_first_not_of(" "), v.size()));
		return v;
	}

	template<typename T>
	constexpr bool is_int64_v = std::is_same<T, std::int64_t>::value || std::is_same<T, std::uint64_t>::value;

	enum class http_method {
		DEL,
		GET,
		HEAD,
		POST,
		PUT,
		CONNECT,
		OPTIONS,
		TRACE
	};

	constexpr inline auto GET = http_method::GET;
	constexpr inline auto POST = http_method::POST;
	constexpr inline auto DEL = http_method::DEL;
	constexpr inline auto HEAD = http_method::HEAD;
	constexpr inline auto TRACE = http_method::TRACE;
	constexpr inline auto OPTIONS = http_method::OPTIONS;
	constexpr inline auto PUT = http_method::PUT;
	constexpr inline auto CONNECT = http_method::CONNECT;

	inline constexpr std::string_view method_name(http_method method) {
		switch (method) {
			case Http::http_method::DEL:
				return "DELETE"sv;
				break;
			case Http::http_method::GET:
				return "GET"sv;
			case Http::http_method::POST:
				return "POST"sv;
				break;
			case Http::http_method::HEAD:
				return "HEAD"sv;
				break;
			case Http::http_method::TRACE:
				return "TRACE"sv;
				break;
			case Http::http_method::OPTIONS:
				return "OPTIONS"sv;
				break;
			case Http::http_method::PUT:
				return "PUT"sv;
				break;
			case Http::http_method::CONNECT:
				return "CONNECT"sv;
				break;
			default:
				return "UNKNOWN"sv;
				break;
		}
	}

	// reduce the code ......
	constexpr std::string_view
	type_to_name(std::integral_constant<http_method, http_method::GET>) noexcept { return "GET"sv; }

	constexpr std::string_view
	type_to_name(std::integral_constant<http_method, http_method::POST>) noexcept { return "POST"sv; }

	constexpr std::string_view
	type_to_name(std::integral_constant<http_method, http_method::DEL>) noexcept { return "DELETE"sv; }

	constexpr std::string_view
	type_to_name(std::integral_constant<http_method, http_method::HEAD>) noexcept { return "HEAD"sv; }

	constexpr std::string_view
	type_to_name(std::integral_constant<http_method, http_method::TRACE>) noexcept { return "TRACE"sv; }

	constexpr std::string_view
	type_to_name(std::integral_constant<http_method, http_method::OPTIONS>) noexcept { return "OPTIONS"sv; }

	constexpr std::string_view
	type_to_name(std::integral_constant<http_method, http_method::PUT>) noexcept { return "PUT"sv; }

	constexpr std::string_view
	type_to_name(std::integral_constant<http_method, http_method::CONNECT>) noexcept { return "CONNECT"sv; }

	inline bool equal(const char *s, size_t l, const char *t) {
		if (strlen(t) != l)
			return false;

		for (size_t i = 0; i < l; ++i) {
			if (std::tolower(s[i]) != std::tolower(t[i]))
				return false;
		}
		return true;
	}

	// parse IP
	inline std::vector<std::string_view> split(std::string_view s, std::string_view delimiter) {
		size_t start = 0;
		size_t end = s.find_first_of(delimiter);

		std::vector<std::string_view> res;

		while (end <= std::string_view::npos) {
			res.emplace_back(s.substr(start, end - start));
			if (end == std::string_view::npos)
				break;
			start = end + 1;
			end = s.find_first_of(delimiter);
		}
		return res;
	}

	inline void remove_char(std::string &str, const char ch) {
		str.erase(std::remove(str.begin(), str.end(), ch), str.end());
	}

}

#endif //INTERVIEW_CPP_UTILS_H
