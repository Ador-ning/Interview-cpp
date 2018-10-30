//
// Created by ning on 2018/10/29.
//

#ifndef INTERVIEW_CPP_UTILS_H
#define INTERVIEW_CPP_UTILS_H

#pragma once

#include <string>
#include <sstream>
#include <iomanip>
#include <cstddef>  // std::byte
#include <cstdlib>
#include <string_view>  // point
#include <map>
#include <tuple>
#include <vector>
#include <algorithm>
#include <type_traits>  // point
#include <cctype>
#include <iostream>
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

	// var bools = [];
	// var valid_chr = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_.-';
	// for(var i = 0; i <= 127; ++ i) {
	// 	var contain = valid_chr.indexOf(String.fromCharCode(i)) == -1;
	// 	bools.push(contain?false:true);
	// }
	// console.log(JSON.stringify(bools))
	// 浏览器运行 js 生成 valid_chr 数组
	inline const constexpr bool valid_chr[128] = {
			false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
			false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
			false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
			true, true, false, true, true, true, true, true, true, true, true, true, true, false, false, false, false,
			false, false, false, true, true, true, true, true, true, true, true, true, true, true, true, true, true,
			true, true, true, true, true, true, true, true, true, true, true, true, false, false, false, false, true,
			false, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true,
			true, true, true, true, true, true, true, true, true, false, false, false, false, false
	};

	inline std::ostringstream &quote_impl(std::ostringstream &os, std::string_view str,
	                                      std::string_view safe) {
		os << std::setiosflags(std::ios::right) << std::setfill('0');
		auto begin = reinterpret_cast<const std::byte *>(str.data());
		auto end = begin + sizeof(char) * str.size();

		std::for_each(begin, end, [&os, &safe](auto &chr) {
			char chrVal = (char) chr;
			unsigned intVal = (unsigned) chr;
			if ((intVal > 127 || !valid_chr[intVal]) && safe.find(chrVal) == std::string_view::npos)
				os << '%' << std::setw(2) << std::hex << std::uppercase << intVal;
			else
				os << chrVal;
		});
		return os;
	}

	inline const std::string quote(std::string_view str) {
		std::ostringstream os;
		return quote_impl(os, str, "/").str();
	}

	inline const std::string quote_plus(std::string_view str) {
		if (str.find(' ') == std::string_view::npos)
			return quote(str);

		std::ostringstream os;
		auto strVal = quote_impl(os, str, " ").str();
		std::replace(strVal.begin(), strVal.end(), ' ', '+');
		return strVal;
	}

	std::string from_url_decode(const std::string &src) {
		std::string res;
		char ch;
		int i, j;
		for (i = 0; i < src.length(); ++i) {
			if (int(src[i]) == 37) {
				sscanf(src.substr(i + 1, 2).c_str(), "%x", &j);
				ch = static_cast<char>(j);
				res += ch;
				i = i + 2;
			} else
				res += src[i];
		}
		return res;
	}

	inline bool is_from_url_encode(std::string_view str) {
		return str.find("%") != std::string_view::npos || str.find("+") != std::string_view::npos;
	}

	inline std::string_view get_extension(std::string_view name) {
		size_t pos = name.rfind('.');
		if (pos == std::string_view::npos)
			return {};
		return name.substr(pos);
	}

	inline std::string to_hex_string(std::size_t value) {
		std::ostringstream os;
		os << std::hex << value;
		return os.str();
	}

	inline const char *MAP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	                         "abcdefghijklmnopqrstuvwxyz"
	                         "0123456789+/";
	inline const char *MAP_URL_ENCODED = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	                                     "abcdefghijklmnopqrstuvwxyz"
	                                     "0123456789-_";

	inline size_t base64_encode(char *_dst, const char *_src, size_t len, int url_encoded) {
		char *dst = _dst;
		const uint8_t *src = reinterpret_cast<const uint8_t *>(_src);
		const char *map = url_encoded ? MAP_URL_ENCODED : MAP;
		uint32_t quad;

		for (; len >= 3; src += 3, len -= 3) {
			quad = ((uint32_t) src[0] << 16) | ((uint32_t) src[1] << 8) | src[2];
			*dst++ = map[quad >> 18];
			*dst++ = map[(quad >> 12) & 63];
			*dst++ = map[(quad >> 6) & 63];
			*dst++ = map[quad & 63];
		}

		if (len != 0) {
			quad = (uint32_t) src[0] << 16;
			*dst++ = map[quad >> 18];
			if (len == 2) {
				quad |= (uint32_t) src[1] << 8;
				*dst++ = map[(quad >> 12) & 63];
				*dst++ = map[(quad >> 6) & 63];
				if (!url_encoded)
					*dst++ = '=';
			} else {
				*dst++ = map[(quad >> 12) & 63];
				if (!url_encoded) {
					*dst++ = '=';
					*dst++ = '=';
				}
			}
		}
		*dst = '\0';
		return dst - _dst;
	}

	inline bool is_valid_utf8(unsigned char *s, size_t length) {
		for (unsigned char *e = s + length; s != e;) {
			if (s + 4 <= e && ((*(uint32_t *) s) & 0x80808080) == 0) {
				s += 4;
			} else {
				while (!(*s & 0x80)) {
					if (++s == e) {
						return true;
					}
				}

				if ((s[0] & 0x60) == 0x40) {
					if (s + 1 >= e || (s[1] & 0xc0) != 0x80 || (s[0] & 0xfe) == 0xc0) {
						return false;
					}
					s += 2;
				} else if ((s[0] & 0xf0) == 0xe0) {
					if (s + 2 >= e || (s[1] & 0xc0) != 0x80 || (s[2] & 0xc0) != 0x80 ||
					    (s[0] == 0xe0 && (s[1] & 0xe0) == 0x80) || (s[0] == 0xed && (s[1] & 0xe0) == 0xa0)) {
						return false;
					}
					s += 3;
				} else if ((s[0] & 0xf8) == 0xf0) {
					if (s + 3 >= e || (s[1] & 0xc0) != 0x80 || (s[2] & 0xc0) != 0x80 || (s[3] & 0xc0) != 0x80 ||
					    (s[0] == 0xf0 && (s[1] & 0xf0) == 0x80) || (s[0] == 0xf4 && s[1] > 0x8f) || s[0] > 0xf4) {
						return false;
					}
					s += 4;
				} else {
					return false;
				}
			}
		}
		return true;
	}


	void xtoa(unsigned long val, char *buf, unsigned radix, int is_neg) {
		char *p;    /* pointer to traverse string */
		char *firstdig;   /* pointer to first digit */
		char temp;    /* temp char */
		unsigned digval;  /* value of digit */

		p = buf;

		if (is_neg) {
			/* negative, so output '-' and negate */
			*p++ = '-';
			val = (unsigned long) (-(long) val);
		}
		firstdig = p;     /* save pointer to first digit */
		do {
			digval = (unsigned) (val % radix);
			val /= radix;   /* get next digit */
			/* convert to ascii and store */
			if (digval > 9)
				*p++ = (char) (digval - 10 + 'a');  /* a letter */
			else
				*p++ = (char) (digval + '0');       /* a digit */
		} while (val > 0);

		/* We now have the digit of the number in the buffer, but in reverse
	   order.  Thus we reverse them now. */
		*p-- = '\0';    /* terminate string; p points to last digit */
		do {
			temp = *p;
			*p = *firstdig;
			*firstdig = temp;   /* swap *p and *firstdig */
			--p;
			++firstdig;   /* advance to next two digits */
		} while (firstdig < p); /* repeat until halfway */
	}

	void itoa(int val, char *buf, int radix) {
		if (radix == 10 && val < 0)
			xtoa((unsigned long) val, buf, radix, 1);
		else
			xtoa((unsigned long) (unsigned int) val, buf, radix, 0);
	}

	template<typename T>
	inline std::string to_str(T &&value) {
		using U= std::remove_const_t<std::remove_reference_t<T>>;
		if constexpr (std::is_integral_v<U> && !is_int64_v<U>) {
			std::vector<char> temp(20, '\0');
			itoa(value, temp.data(), 10);  // not find the lib
			return std::string(temp.data());
		} else if constexpr (is_int64_v<U>) {
			std::vector<char> temp(65, '\0');
			xtoa(value, temp.data(), 10, std::is_signed_v<U>);  // not find the lib

			return std::string(temp.data());
		} else if constexpr (std::is_floating_point_v<U>) {
			std::vector<char> temp(20, '\0');
			sprintf(temp.data(), "%f", value);
			return std::string(temp.data());
		} else if constexpr (std::is_same_v<std::string, U> || std::is_same_v<const char *, U>) {
			return value;
		} else
			std::cout << "This type has not supported yet." << std::endl;
	}

#define HAS_MEMBER(member)\
template<typename T, typename... Args>\
struct has_##member\
{\
private:\
    template<typename U> static auto Check(int) -> decltype(std::declval<U>().member(std::declval<Args>()...), std::true_type()); \
    template<typename U> static std::false_type Check(...);\
public:\
    enum{value = std::is_same<decltype(Check<T>(0)), std::true_type>::value};\
};

	HAS_MEMBER(before)

	HAS_MEMBER(after)

	template<typename ...Args, typename F, std::size_t ...Idx>
	constexpr void for_each_l(std::tuple<Args...> &t, F &&f, std::index_sequence<Idx...>) {
		(std::forward<F>(f)(std::get<size_t>(t)), Idx); // 处理参数 函数
	}
}

#endif //INTERVIEW_CPP_UTILS_H
