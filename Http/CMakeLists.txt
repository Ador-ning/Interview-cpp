cmake_minimum_required(VERSION 2.8)
project(http)

find_package(Threads)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++17")

find_package(OpenSSL REQUIRED)
find_package(Boost 1.67.0 REQUIRED COMPONENTS system filesystem)

add_subdirectory(ormpp) # connector to DataBase
add_subdirectory(iguana) # parser for JSON, XML and PlainText

