//
// Created by ning on 2018/9/26.
//

#ifdef _WINDOWS
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <string.h>
#include "leptjson.h"

#define EXCEPT(c, ch) do { assert(*c->json == (ch)); c->json++; } while(0)
#define ISDIGIT1TO9(ch) ((ch) >= '1' && (ch) <= '9')
#define ISDIGIT(ch) ((ch) >= '0' && (ch) <= '9')
#define PUTC(c, ch) do {  *(char*)lept_context_push(c, sizeof(char)) = (ch); } while(0)

#ifndef LEPT_PARSE_STACK_INIT_SIZE
#define LEPT_PARSE_STACK_INIT_SIZE 256
#endif

// convert context info using
typedef struct {
	char *stack;
	const char *json;
	size_t size, top; // stack + json
} lept_context;

static void *lept_context_push(lept_context *c, size_t size) {
	void *ret;
	if (c->top + size >= c->size) { // realloc the memory
		if (c->size == 0)
			c->size = LEPT_PARSE_STACK_INIT_SIZE;
		while (c->top + size >= c->size)
			c->size += c->size >> 1;    // 1.5 c->size

		c->stack = (char *) realloc(c->stack, c->size);
	}
	ret = c->stack + c->top;
	c->top += size;
	return ret;
}

static void *lept_context_pop(lept_context *c, size_t size) {
	assert(c->top >= size);
	return c->stack + (c->top -= size);
}

void lept_free(lept_value *v) {
	assert(v != NULL);
	if (v->type == LEPT_STRING)
		free(v->u.s.s);
	v->type = LEPT_NULL;
}
// ----------------------------------------------------------------------------

// static parse functions
// remove white space
static void lept_parse_whitespace(lept_context *c) {
	const char *p = c->json;
	while (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r')
		p++;
	c->json = p;
}

// parse number
static int lept_parse_number(lept_context *c, lept_value *v) {
	const char *p = c->json;

	if (*p == '-')
		p++;    // 负号
	// 整数
	if (*p == '0')
		p++;
	else {
		if (!ISDIGIT1TO9(*p))
			return LEPT_PARSE_INVALID_VALUE;
		for (p++; ISDIGIT(*p); p++);
	}

	// 小数部分
	if (*p == '.') {
		p++;
		if (!ISDIGIT(*p))
			return LEPT_PARSE_INVALID_VALUE;
		for (p++; ISDIGIT(*p); p++);
	}

	// 指数
	if (*p == 'e' || *p == 'E') {
		p++;
		if (*p == '+' || *p == '-')
			p++;
		if (!ISDIGIT(*p))
			return LEPT_PARSE_INVALID_VALUE;
		for (p++; ISDIGIT(*p); p++);
	}

	errno = 0;
	v->u.n = strtod(c->json, NULL);   // str to double / str to float / str to long
	if (errno == ERANGE && (v->u.n == HUGE_VAL || v->u.n == -HUGE_VAL))
		return LEPT_PARSE_NUMBER_TOO_BIG;
	c->json = p;
	v->type = LEPT_NUMBER;
	return LEPT_PARSE_OK;
}

// parse true / false / null
static int lept_parse_literal(lept_context *c, lept_value *v, const char *literal,
                              lept_type type) {
	size_t i;
	EXCEPT(c, literal[0]);
	for (i = 0; literal[i + 1]; ++i) {
		if (c->json[i] != literal[i + 1])
			return LEPT_PARSE_INVALID_VALUE;
	}
	c->json += i;
	v->type = type;
	return LEPT_PARSE_OK;
}

// parse string
static int lept_parse_string(lept_context *c, lept_value *v) {
	size_t head = c->top, len;
	const char *p;
	EXCEPT(c, '\"');
	p = c->json;
	for (;;) {
		char ch = *p++;
		switch (ch) {
			case '\"':  // the end of string
				len = c->top - head;
				lept_set_string(v, (const char *) lept_context_pop(c, len), len);
				c->json = p;
				return LEPT_PARSE_OK;
			case '\0':
				c->top = head;
				return LEPT_PARSE_MISS_QUOTATION_MARK;
			case '\\': // 转义序列解析
				switch (*p++) {
					case '\\':
						PUTC(c, '\\');
						break;
					case '\"':
						PUTC(c, '\"');
						break;
					case '/':
						PUTC(c, '/');
						break;
					case 'b':
						PUTC(c, '\b');
						break;
					case 'f':
						PUTC(c, '\f');
						break;
					case 'n':
						PUTC(c, '\n');
						break;
					case 'r':
						PUTC(c, '\r');
						break;
					case 't':
						PUTC(c, '\t');
						break;

					default:
						c->top = head;
						return LEPT_PARSE_INVALID_STRING_ESCAPE;
				}
				break;
			default:
				if ((unsigned char) ch < 0x20) {
					c->top = head;
					return LEPT_PARSE_INVALID_STRING_CHAR;
				}
				PUTC(c, ch);
		}
	}
}

// parse interface
static int lept_parse_value(lept_context *c, lept_value *v) {
	switch (*c->json) {
		case 'n' :
			return lept_parse_literal(c, v, "null", LEPT_NULL);
		case 't':
			return lept_parse_literal(c, v, "true", LEPT_TRUE);
		case 'f':
			return lept_parse_literal(c, v, "false", LEPT_FALSE);
		case '"':
			return lept_parse_string(c, v);
		case '\0':
			return LEPT_PARSE_EXPECT_VALUE;
		default:
			return lept_parse_number(c, v);
	}
}

int lept_parse(lept_value *v, const char *json) {
	lept_context c;
	int ret;
	assert(v != NULL);
	c.json = json;
	c.stack = NULL;
	c.size = c.top = 0;
	lept_init(v);

	// remove white spaces in the beginning of JSON text
	lept_parse_whitespace(&c);
	if ((ret = lept_parse_value(&c, v)) == LEPT_PARSE_OK) {
		lept_parse_whitespace(&c);
		if (*c.json != '\0') {
			v->type = LEPT_NULL;
			ret = LEPT_PARSE_ROOT_NOT_SINGULAR;
		}
	}

	assert(c.top == 0);
	free(c.stack);
	return ret;
}
// ----------------------------------------------------------------------------

// get and set value
lept_type lept_get_type(const lept_value *v) {
	assert(v != NULL);
	return v->type;
}

double lept_get_number(const lept_value *v) {
	assert(v != NULL && v->type == LEPT_NUMBER);
	return v->u.n;
}

void lept_set_number(lept_value *v, double b) {
	lept_free(v);
	v->type = LEPT_NUMBER;
	v->u.n = b;
}

int lept_get_boolean(const lept_value *v) {
	assert(v != NULL && (v->type == LEPT_FALSE || v->type == LEPT_TRUE));
	return v->type == LEPT_TRUE;
}

void lept_set_boolean(lept_value *v, int b) {
	lept_free(v);
	v->type = b ? LEPT_TRUE : LEPT_FALSE;
}

const char *lept_get_string(const lept_value *v) {
	assert(v != NULL && v->type == LEPT_STRING);
	return v->u.s.s;
}

size_t lept_get_string_length(const lept_value *v) {
	assert(v != NULL && v->type == LEPT_STRING);
	return v->u.s.len;
}

void lept_set_string(lept_value *v, const char *s, size_t len) {
	assert(v != NULL && (s != NULL || len == 0));
	lept_free(v);
	v->u.s.s = (char *) malloc(len + 1);
	memcpy(v->u.s.s, s, len);
	v->u.s.len = len;
	v->u.s.s[len] = '\0';
	v->type = LEPT_STRING;
}
// ----------------------------------------------------------------------------