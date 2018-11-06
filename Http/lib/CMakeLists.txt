cmake_minimum_required(VERSION 2.8)
project(http CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++17")
add_subdirectory(http)

set(lib_src2 router.cpp)
add_executable(lib_src2_exe ${lib_src2})