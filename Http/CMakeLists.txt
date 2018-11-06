cmake_minimum_required(VERSION 2.8)
project(http CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++17")

find_package(Threads)
find_package(OpenSSL REQUIRED)
find_package(Boost 1.67.0 REQUIRED COMPONENTS system filesystem)

add_subdirectory(ormpp) # connector to DataBase
add_subdirectory(iguana) # parser for JSON, XML and PlainText
add_subdirectory(lib_http)
add_subdirectory(lib)

include_directories(
		${Boost_INCLUDE_DIR}
		${OPENSSL_INCLUDE_DIR}
		${CMAKE_SOURCE_DIR}
		"${CMAKE_SOURCE_DIR}/lib_http"  #
		"${CMAKE_SOURCE_DIR}/lib"       #
		"${CMAKE_SOURCE_DIR}/iguana")   # 序列化

find_package(Boost 1.67.0 COMPONENTS coroutine context system thread filesystem REQUIRED)

# sub dir
set(FILES ${lib_src1} ${lib_src2})
set(HTTP_FILES ${lib_http_src1} ${lib_http_src2})

set(HTTP_TEST_FILES examples/main.cpp)
set(DATABASE_TEST examples/database.cpp)
set(FILE_EXAMPLE examples/file_manager.cpp)
set(WEBSOCKET_EXAMPLE examples/websocket.cpp)

# static library
add_library(http_lib STATIC ${HTTP_FLIES})
set_target_properties(http_lib PROPERTIES LINKER_LANGUAGE CXX)

add_library(lib STATIC ${FLIES})
set_target_properties(lib PROPERTIES LINKER_LANGUAGE CXX)

add_executable(http_examples ${HTTP_TEST_FILES})
add_executable(database_example ${DATABASE_TEST})
add_executable(file_example ${FILE_EXAMPLE})
add_executable(websocket_example ${WEBSOCKET_EXAMPLE})

if (WIN32)
	set(EXTRA_LIB mswsock ws2_32)
endif ()

target_link_libraries(http_examples lib http_lib ${Boost_LIBRARIES} ${OPENSSL_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(database_example lib http_lib mysqlclient ${Boost_LIBRARIES} ${OPENSSL_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(file_example lib http_lib ${Boost_LIBRARIES} ${OPENSSL_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(websocket_example lib http _lib ${Boost_LIBRARIES} ${OPENSSL_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

# install configure