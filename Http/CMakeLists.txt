cmake_minimum_required(VERSION 3.10)

set(project_name http)
project(${project_name})

if (MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest")
else ()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -pthread -std=c++17")
endif ()

#option(ENABLE_SSL   "Set to switch to build use ssl"  OFF)
#option(ENABLE_GZIP  "Set to switch to build use gzip" OFF)
set(ENABLE_GZIP ON)
set(ENABLE_SSL ON)
set(ENABLE_CLIENT_SSL ON)

if (ENABLE_SSL)
	add_definitions(-DCINATRA_ENABLE_SSL)
	message(STATUS "Use SSL")
endif ()

if (ENABLE_GZIP)
	add_definitions(-DCINATRA_ENABLE_GZIP)
endif ()

if (ENABLE_CLIENT_SSL)
	add_definitions(-DCINATRA_ENABLE_CLIENT_SSL)
endif ()

# ## find boost
set(BOOST_ROOT "/usr/local/Cellar/boost/1.67.0_1")
find_package(Boost 1.67.0 REQUIRED COMPONENTS system)
link_directories(${Boost_LIBRARY_DIRS})

if (ENABLE_SSL)
	find_package(OpenSSL REQUIRED)
endif ()
if (ENABLE_CLIENT_SSL)
	find_package(OpenSSL REQUIRED)
endif ()
if (ENABLE_GZIP)
	find_package(ZLIB REQUIRED)
endif ()


set(http
		mime_types.cpp
		io_service_pool.cpp
		gzip.cpp test.cpp
		define.h
		define_ws.h
		utils.h
		# uuids.h
		sha1.cpp
		use_asio.cpp
		function_traits.cpp
		sha1.cpp
		test.cpp
		)


add_executable(${project_name} ${http})

include_directories(${Boost_INCLUDE_DIRS} ${OPENSSL_INCLUDE_DIR})

target_link_libraries(${project_name} ${Boost_LIBRARIES} uuid -lstdc++fs)
if (ENABLE_SSL)
	target_link_libraries(${project_name} ${OPENSSL_LIBRARIES} pthread -ldl)
endif ()
if (ENABLE_CLIENT_SSL)
	target_link_libraries(${project_name} ${OPENSSL_LIBRARIES} pthread -ldl)
endif ()
if (ENABLE_GZIP)
	target_link_libraries(${project_name} ${ZLIB_LIBRARIES})
endif ()

install(TARGETS ${project_name} DESTINATION include)