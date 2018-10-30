cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

add_executable(http test.cpp)

add_library(http_www test.cpp define.h define_ws.h utils.h uuids.h)