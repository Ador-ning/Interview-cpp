cmake_minimum_required(VERSION 3.1)
project(leptjson_test C)

if (CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ansi -pedantic -Walll")
endif ()

add_library(leptjson leptjson.c)