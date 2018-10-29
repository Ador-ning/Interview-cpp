//
// Created by ning on 2018/10/29.
//

#ifndef INTERVIEW_CPP_DEFINE_WS_H
#define INTERVIEW_CPP_DEFINE_WS_H

#pragma once

#include <cstdint>
#include <string_view>

namespace Http {
	// using namespace std::string_view_literals;

#if defined(_WIN32)
#define __SWAP_LONGLONG(l)            \
			( ( ((l) >> 56) & 0x00000000000000FFLL ) |       \
			  ( ((l) >> 40) & 0x000000000000FF00LL ) |       \
			  ( ((l) >> 24) & 0x0000000000FF0000LL ) |       \
			  ( ((l) >>  8) & 0x00000000FF000000LL ) |       \
			  ( ((l) <<  8) & 0x000000FF00000000LL ) |       \
			  ( ((l) << 24) & 0x0000FF0000000000LL ) |       \
			  ( ((l) << 40) & 0x00FF000000000000LL ) |       \
			  ( ((l) << 56) & 0xFF00000000000000LL ) )


	inline uint64_t htobe64(uint64_t val) {
		const uint64_t ret = __SWAP_LONGLONG(val);
		return ret;
	}

	inline uint64_t be64toh(uint64_t val) {
		const uint64_t ret = __SWAP_LONGLONG(val);
		return ret;
	}

#elif defined(__APPLE__)

#include <libkern/OSByteOrder.h>

#define be64toh(x) OSSwapBigToHostInt64(x)
#define htobe64(x) OSSwapHostToBigInt64(x)
#endif // _WIN32

	enum opcode : std::uint8_t {
		cont = 0,
		text = 1,
		binary = 2,
		rsv3 = 3,
		rsv4 = 4,
		rsv5 = 5,
		rsv6 = 6,
		rsv7 = 7,
		close = 8,
		ping = 9,
		pong = 10,
		crsvb = 11,
		crsvc = 12,
		crsvd = 13,
		crsve = 14,
		crsvf = 15,
	};

	/* Close status code -- These codes accompany close frames.
	 * */
	enum close : std::uint16_t {
		normal = 1000,
		going_away = 1001,  // a server failure or the browser is navigating away
		protocol_error = 1002,
		unknown_data = 1003, // received data type it cannot accept
		bad_payload = 1007, // received data contained inconsistent data
		policy_error = 1008, // received a message that violates its policy
		too_big = 1009, // data frame too large
		needs_extension = 1010, //
		internal_error = 1011, // encountered an unexpected condition
		service_restart = 1012,
		try_again_later = 1013, //
		/*
		 * This code is reserved and may not be sent
		 * */
				none = 0,
		reserved1 = 1004,
		no_status = 1005,
		abnormal = 1006,
		reserved2 = 1014,
		reserved3 = 1015
	};

	// frame type
	enum class ws_frame_type {
		WS_ERROR_FRAME = 0xFF00,
		WS_INCOMPLETE_FRAME = 0xFE00,

		WS_OPENING_FRAME = 0x3300,
		WS_CLOSING_FRAME = 0x3400,

		WS_INCOMPLETE_TEXT_FRAME = 0x01,
		WS_INCOMPLETE_BINARY_FRAME = 0x02,

		WS_TEXT_FRAME = 0x81,
		WS_BINARY_FRAME = 0x82,
		WS_RSV3_FRAME = 0x83,
		WS_RSV4_FRAME = 0x84,
		WS_RSV5_FRAME = 0x85,
		WS_RSV6_FRAME = 0x86,
		WS_RSV7_FRAME = 0x87,
		WS_CLOSE_FRAME = 0x88,
		WS_PING_FRAME = 0x89,
		WS_PONG_FRAME = 0x8A,
	};

	struct close_frame {
		std::uint16_t code;
		char *message;
		size_t length;
	};

	enum ws_head_len {
		SHORT_HEADER = 6,
		MEDIUM_HEADER = 8,
		LONG_HEADER = 14,
		INVALID_HEADER
	};

	enum ws_send_state {
		SEND_CONTINUATION = 1,
		SEND_NO_FIN = 2,
		SEND_COMPRESSED = 64,
	};

#define WEBSOCKET_FRAME_MAXLEN 16384
#define WEBSOCKET_PAYLOAD_SINGLE 125
#define WEBSOCKET_PAYLOAD_EXTEND_1 126
#define WEBSOCKET_PAYLOAD_EXTEND_2 127

	inline constexpr const std::string_view WEBSOCKET = "websocket"sv;
	inline constexpr const std::string_view UNGRADE = "upgrade"sv;
	inline constexpr const char sw_guid[] = "258EAFA5-E914-47DA-95CA-C5AB0DC85B11";
}

#endif //INTERVIEW_CPP_DEFINE_WS_H
