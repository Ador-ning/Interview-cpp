cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

add_executable(http test.cpp)

add_library(http_www mime_types.cpp test.cpp define.h define_ws.h utils.h uuids.h sha1.cpp use_asio.cpp function_traits.cpp sha1.cpp)