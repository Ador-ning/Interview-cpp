cmake_minimum_required(VERSION 2.8)
project(http CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++17")

set(lib_http_src1
		connection.cpp
		http_server.h
		http_parser.h
		io_service_pool.h
		mime_types.h
		multipart_parser.h
		picohttpparser.h
		response.h
		request.h
		utils.h
		websocket.h)

add_executable(lib_http_src1_exe ${lib_http_src1})