cmake_minimum_required(VERSION 3.10)

project(leptjson_test C)

add_subdirectory(src)

add_executable(leptjson_test test.c)

target_link_libraries(leptjson_test leptjson)