cmake_minimum_required(VERSION 2.8)
project(http CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++17")
add_subdirectory(http)

set(lib_http_src2
		http_server.cpp
		http_parser.cpp
		io_service_pool.cpp
		mime_type.cpp
		multipart_parser.cpp    # http parser
		picohttpparser.cpp
		request.cpp
		response.cpp
		utils.cpp
		websocket.cpp)

add_executable(lib_http_src2_exe ${lib_http_src2})

