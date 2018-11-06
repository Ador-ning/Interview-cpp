//
// Created by ning on 2018/11/1.
//

#ifndef INTERVIEW_CPP_MULTIPART_PARSER_H
#define INTERVIEW_CPP_MULTIPART_PARSER_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdlib.h>
#include <ctype.h>
#include <memory.h>

typedef struct multipart_parser multipart_parser;
typedef struct multipart_parser_settings multipart_parser_settings;
typedef struct multipart_parser_state multipart_parser_state;

typedef int (*multipart_data_cb)(multipart_parser *, const char *at, size_t length);

typedef int (*multipart_notify_cb)(multipart_parser *);

struct multipart_parser_settings {
	multipart_data_cb on_header_field;
	multipart_data_cb on_header_value;
	multipart_data_cb on_part_data;

	multipart_data_cb on_part_data_begin;
	multipart_data_cb on_headers_complete;
	multipart_data_cb on_part_data_end;
	multipart_data_cb on_body_end;
};

multipart_parser *multipart_parser_init(const char *boundary, const multipart_parser_setting *settings);

void multipart_parser_fee(multipart_parser *p);

size_t multipart_parser_execute(multipart_parser *p, const char *buf, size_t len);

void multipart_parser_set_data(multipart_parser *p, void *data);

void *multipart_parser_get_data(multipart_parser *p);

#endif __cplusplus
}
#endif

#endif //INTERVIEW_CPP_MULTIPART_PARSER_H