cmake_minimum_required(VERSION 2.8)
project(http CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++17")

set(lib_src1
		./middleware/cookies.cpp
		./middleware/session.cpp
		aop.cpp
		context_container.cpp
		function_traits.cpp
		http_router.h
		http.h
		router.h)

add_executable(lib_src1_exe  ${lib_src1})