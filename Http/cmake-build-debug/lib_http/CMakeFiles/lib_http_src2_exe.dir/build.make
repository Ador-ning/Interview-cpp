# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ning/Interview-cpp/Http

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ning/Interview-cpp/Http/cmake-build-debug

# Include any dependencies generated for this target.
include lib_http/CMakeFiles/lib_http_src2_exe.dir/depend.make

# Include the progress variables for this target.
include lib_http/CMakeFiles/lib_http_src2_exe.dir/progress.make

# Include the compile flags for this target's objects.
include lib_http/CMakeFiles/lib_http_src2_exe.dir/flags.make

lib_http/CMakeFiles/lib_http_src2_exe.dir/http_server.cpp.o: lib_http/CMakeFiles/lib_http_src2_exe.dir/flags.make
lib_http/CMakeFiles/lib_http_src2_exe.dir/http_server.cpp.o: ../lib_http/http_server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Interview-cpp/Http/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib_http/CMakeFiles/lib_http_src2_exe.dir/http_server.cpp.o"
	cd /Users/ning/Interview-cpp/Http/cmake-build-debug/lib_http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lib_http_src2_exe.dir/http_server.cpp.o -c /Users/ning/Interview-cpp/Http/lib_http/http_server.cpp

lib_http/CMakeFiles/lib_http_src2_exe.dir/http_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib_http_src2_exe.dir/http_server.cpp.i"
	cd /Users/ning/Interview-cpp/Http/cmake-build-debug/lib_http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Interview-cpp/Http/lib_http/http_server.cpp > CMakeFiles/lib_http_src2_exe.dir/http_server.cpp.i

lib_http/CMakeFiles/lib_http_src2_exe.dir/http_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib_http_src2_exe.dir/http_server.cpp.s"
	cd /Users/ning/Interview-cpp/Http/cmake-build-debug/lib_http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Interview-cpp/Http/lib_http/http_server.cpp -o CMakeFiles/lib_http_src2_exe.dir/http_server.cpp.s

lib_http/CMakeFiles/lib_http_src2_exe.dir/http_server.cpp.o.requires:

.PHONY : lib_http/CMakeFiles/lib_http_src2_exe.dir/http_server.cpp.o.requires

lib_http/CMakeFiles/lib_http_src2_exe.dir/http_server.cpp.o.provides: lib_http/CMakeFiles/lib_http_src2_exe.dir/http_server.cpp.o.requires
	$(MAKE) -f lib_http/CMakeFiles/lib_http_src2_exe.dir/build.make lib_http/CMakeFiles/lib_http_src2_exe.dir/http_server.cpp.o.provides.build
.PHONY : lib_http/CMakeFiles/lib_http_src2_exe.dir/http_server.cpp.o.provides

lib_http/CMakeFiles/lib_http_src2_exe.dir/http_server.cpp.o.provides.build: lib_http/CMakeFiles/lib_http_src2_exe.dir/http_server.cpp.o


lib_http/CMakeFiles/lib_http_src2_exe.dir/http_parser.cpp.o: lib_http/CMakeFiles/lib_http_src2_exe.dir/flags.make
lib_http/CMakeFiles/lib_http_src2_exe.dir/http_parser.cpp.o: ../lib_http/http_parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Interview-cpp/Http/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object lib_http/CMakeFiles/lib_http_src2_exe.dir/http_parser.cpp.o"
	cd /Users/ning/Interview-cpp/Http/cmake-build-debug/lib_http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lib_http_src2_exe.dir/http_parser.cpp.o -c /Users/ning/Interview-cpp/Http/lib_http/http_parser.cpp

lib_http/CMakeFiles/lib_http_src2_exe.dir/http_parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib_http_src2_exe.dir/http_parser.cpp.i"
	cd /Users/ning/Interview-cpp/Http/cmake-build-debug/lib_http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Interview-cpp/Http/lib_http/http_parser.cpp > CMakeFiles/lib_http_src2_exe.dir/http_parser.cpp.i

lib_http/CMakeFiles/lib_http_src2_exe.dir/http_parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib_http_src2_exe.dir/http_parser.cpp.s"
	cd /Users/ning/Interview-cpp/Http/cmake-build-debug/lib_http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Interview-cpp/Http/lib_http/http_parser.cpp -o CMakeFiles/lib_http_src2_exe.dir/http_parser.cpp.s

lib_http/CMakeFiles/lib_http_src2_exe.dir/http_parser.cpp.o.requires:

.PHONY : lib_http/CMakeFiles/lib_http_src2_exe.dir/http_parser.cpp.o.requires

lib_http/CMakeFiles/lib_http_src2_exe.dir/http_parser.cpp.o.provides: lib_http/CMakeFiles/lib_http_src2_exe.dir/http_parser.cpp.o.requires
	$(MAKE) -f lib_http/CMakeFiles/lib_http_src2_exe.dir/build.make lib_http/CMakeFiles/lib_http_src2_exe.dir/http_parser.cpp.o.provides.build
.PHONY : lib_http/CMakeFiles/lib_http_src2_exe.dir/http_parser.cpp.o.provides

lib_http/CMakeFiles/lib_http_src2_exe.dir/http_parser.cpp.o.provides.build: lib_http/CMakeFiles/lib_http_src2_exe.dir/http_parser.cpp.o


lib_http/CMakeFiles/lib_http_src2_exe.dir/io_service_pool.cpp.o: lib_http/CMakeFiles/lib_http_src2_exe.dir/flags.make
lib_http/CMakeFiles/lib_http_src2_exe.dir/io_service_pool.cpp.o: ../lib_http/io_service_pool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Interview-cpp/Http/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object lib_http/CMakeFiles/lib_http_src2_exe.dir/io_service_pool.cpp.o"
	cd /Users/ning/Interview-cpp/Http/cmake-build-debug/lib_http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lib_http_src2_exe.dir/io_service_pool.cpp.o -c /Users/ning/Interview-cpp/Http/lib_http/io_service_pool.cpp

lib_http/CMakeFiles/lib_http_src2_exe.dir/io_service_pool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib_http_src2_exe.dir/io_service_pool.cpp.i"
	cd /Users/ning/Interview-cpp/Http/cmake-build-debug/lib_http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Interview-cpp/Http/lib_http/io_service_pool.cpp > CMakeFiles/lib_http_src2_exe.dir/io_service_pool.cpp.i

lib_http/CMakeFiles/lib_http_src2_exe.dir/io_service_pool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib_http_src2_exe.dir/io_service_pool.cpp.s"
	cd /Users/ning/Interview-cpp/Http/cmake-build-debug/lib_http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Interview-cpp/Http/lib_http/io_service_pool.cpp -o CMakeFiles/lib_http_src2_exe.dir/io_service_pool.cpp.s

lib_http/CMakeFiles/lib_http_src2_exe.dir/io_service_pool.cpp.o.requires:

.PHONY : lib_http/CMakeFiles/lib_http_src2_exe.dir/io_service_pool.cpp.o.requires

lib_http/CMakeFiles/lib_http_src2_exe.dir/io_service_pool.cpp.o.provides: lib_http/CMakeFiles/lib_http_src2_exe.dir/io_service_pool.cpp.o.requires
	$(MAKE) -f lib_http/CMakeFiles/lib_http_src2_exe.dir/build.make lib_http/CMakeFiles/lib_http_src2_exe.dir/io_service_pool.cpp.o.provides.build
.PHONY : lib_http/CMakeFiles/lib_http_src2_exe.dir/io_service_pool.cpp.o.provides

lib_http/CMakeFiles/lib_http_src2_exe.dir/io_service_pool.cpp.o.provides.build: lib_http/CMakeFiles/lib_http_src2_exe.dir/io_service_pool.cpp.o


lib_http/CMakeFiles/lib_http_src2_exe.dir/mime_type.cpp.o: lib_http/CMakeFiles/lib_http_src2_exe.dir/flags.make
lib_http/CMakeFiles/lib_http_src2_exe.dir/mime_type.cpp.o: ../lib_http/mime_type.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Interview-cpp/Http/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object lib_http/CMakeFiles/lib_http_src2_exe.dir/mime_type.cpp.o"
	cd /Users/ning/Interview-cpp/Http/cmake-build-debug/lib_http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lib_http_src2_exe.dir/mime_type.cpp.o -c /Users/ning/Interview-cpp/Http/lib_http/mime_type.cpp

lib_http/CMakeFiles/lib_http_src2_exe.dir/mime_type.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib_http_src2_exe.dir/mime_type.cpp.i"
	cd /Users/ning/Interview-cpp/Http/cmake-build-debug/lib_http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Interview-cpp/Http/lib_http/mime_type.cpp > CMakeFiles/lib_http_src2_exe.dir/mime_type.cpp.i

lib_http/CMakeFiles/lib_http_src2_exe.dir/mime_type.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib_http_src2_exe.dir/mime_type.cpp.s"
	cd /Users/ning/Interview-cpp/Http/cmake-build-debug/lib_http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Interview-cpp/Http/lib_http/mime_type.cpp -o CMakeFiles/lib_http_src2_exe.dir/mime_type.cpp.s

lib_http/CMakeFiles/lib_http_src2_exe.dir/mime_type.cpp.o.requires:

.PHONY : lib_http/CMakeFiles/lib_http_src2_exe.dir/mime_type.cpp.o.requires

lib_http/CMakeFiles/lib_http_src2_exe.dir/mime_type.cpp.o.provides: lib_http/CMakeFiles/lib_http_src2_exe.dir/mime_type.cpp.o.requires
	$(MAKE) -f lib_http/CMakeFiles/lib_http_src2_exe.dir/build.make lib_http/CMakeFiles/lib_http_src2_exe.dir/mime_type.cpp.o.provides.build
.PHONY : lib_http/CMakeFiles/lib_http_src2_exe.dir/mime_type.cpp.o.provides

lib_http/CMakeFiles/lib_http_src2_exe.dir/mime_type.cpp.o.provides.build: lib_http/CMakeFiles/lib_http_src2_exe.dir/mime_type.cpp.o


lib_http/CMakeFiles/lib_http_src2_exe.dir/multipart_parser.cpp.o: lib_http/CMakeFiles/lib_http_src2_exe.dir/flags.make
lib_http/CMakeFiles/lib_http_src2_exe.dir/multipart_parser.cpp.o: ../lib_http/multipart_parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Interview-cpp/Http/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object lib_http/CMakeFiles/lib_http_src2_exe.dir/multipart_parser.cpp.o"
	cd /Users/ning/Interview-cpp/Http/cmake-build-debug/lib_http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lib_http_src2_exe.dir/multipart_parser.cpp.o -c /Users/ning/Interview-cpp/Http/lib_http/multipart_parser.cpp

lib_http/CMakeFiles/lib_http_src2_exe.dir/multipart_parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib_http_src2_exe.dir/multipart_parser.cpp.i"
	cd /Users/ning/Interview-cpp/Http/cmake-build-debug/lib_http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Interview-cpp/Http/lib_http/multipart_parser.cpp > CMakeFiles/lib_http_src2_exe.dir/multipart_parser.cpp.i

lib_http/CMakeFiles/lib_http_src2_exe.dir/multipart_parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib_http_src2_exe.dir/multipart_parser.cpp.s"
	cd /Users/ning/Interview-cpp/Http/cmake-build-debug/lib_http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Interview-cpp/Http/lib_http/multipart_parser.cpp -o CMakeFiles/lib_http_src2_exe.dir/multipart_parser.cpp.s

lib_http/CMakeFiles/lib_http_src2_exe.dir/multipart_parser.cpp.o.requires:

.PHONY : lib_http/CMakeFiles/lib_http_src2_exe.dir/multipart_parser.cpp.o.requires

lib_http/CMakeFiles/lib_http_src2_exe.dir/multipart_parser.cpp.o.provides: lib_http/CMakeFiles/lib_http_src2_exe.dir/multipart_parser.cpp.o.requires
	$(MAKE) -f lib_http/CMakeFiles/lib_http_src2_exe.dir/build.make lib_http/CMakeFiles/lib_http_src2_exe.dir/multipart_parser.cpp.o.provides.build
.PHONY : lib_http/CMakeFiles/lib_http_src2_exe.dir/multipart_parser.cpp.o.provides

lib_http/CMakeFiles/lib_http_src2_exe.dir/multipart_parser.cpp.o.provides.build: lib_http/CMakeFiles/lib_http_src2_exe.dir/multipart_parser.cpp.o


lib_http/CMakeFiles/lib_http_src2_exe.dir/picohttpparser.cpp.o: lib_http/CMakeFiles/lib_http_src2_exe.dir/flags.make
lib_http/CMakeFiles/lib_http_src2_exe.dir/picohttpparser.cpp.o: ../lib_http/picohttpparser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Interview-cpp/Http/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object lib_http/CMakeFiles/lib_http_src2_exe.dir/picohttpparser.cpp.o"
	cd /Users/ning/Interview-cpp/Http/cmake-build-debug/lib_http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lib_http_src2_exe.dir/picohttpparser.cpp.o -c /Users/ning/Interview-cpp/Http/lib_http/picohttpparser.cpp

lib_http/CMakeFiles/lib_http_src2_exe.dir/picohttpparser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib_http_src2_exe.dir/picohttpparser.cpp.i"
	cd /Users/ning/Interview-cpp/Http/cmake-build-debug/lib_http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Interview-cpp/Http/lib_http/picohttpparser.cpp > CMakeFiles/lib_http_src2_exe.dir/picohttpparser.cpp.i

lib_http/CMakeFiles/lib_http_src2_exe.dir/picohttpparser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib_http_src2_exe.dir/picohttpparser.cpp.s"
	cd /Users/ning/Interview-cpp/Http/cmake-build-debug/lib_http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Interview-cpp/Http/lib_http/picohttpparser.cpp -o CMakeFiles/lib_http_src2_exe.dir/picohttpparser.cpp.s

lib_http/CMakeFiles/lib_http_src2_exe.dir/picohttpparser.cpp.o.requires:

.PHONY : lib_http/CMakeFiles/lib_http_src2_exe.dir/picohttpparser.cpp.o.requires

lib_http/CMakeFiles/lib_http_src2_exe.dir/picohttpparser.cpp.o.provides: lib_http/CMakeFiles/lib_http_src2_exe.dir/picohttpparser.cpp.o.requires
	$(MAKE) -f lib_http/CMakeFiles/lib_http_src2_exe.dir/build.make lib_http/CMakeFiles/lib_http_src2_exe.dir/picohttpparser.cpp.o.provides.build
.PHONY : lib_http/CMakeFiles/lib_http_src2_exe.dir/picohttpparser.cpp.o.provides

lib_http/CMakeFiles/lib_http_src2_exe.dir/picohttpparser.cpp.o.provides.build: lib_http/CMakeFiles/lib_http_src2_exe.dir/picohttpparser.cpp.o


lib_http/CMakeFiles/lib_http_src2_exe.dir/request.cpp.o: lib_http/CMakeFiles/lib_http_src2_exe.dir/flags.make
lib_http/CMakeFiles/lib_http_src2_exe.dir/request.cpp.o: ../lib_http/request.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Interview-cpp/Http/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object lib_http/CMakeFiles/lib_http_src2_exe.dir/request.cpp.o"
	cd /Users/ning/Interview-cpp/Http/cmake-build-debug/lib_http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lib_http_src2_exe.dir/request.cpp.o -c /Users/ning/Interview-cpp/Http/lib_http/request.cpp

lib_http/CMakeFiles/lib_http_src2_exe.dir/request.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib_http_src2_exe.dir/request.cpp.i"
	cd /Users/ning/Interview-cpp/Http/cmake-build-debug/lib_http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Interview-cpp/Http/lib_http/request.cpp > CMakeFiles/lib_http_src2_exe.dir/request.cpp.i

lib_http/CMakeFiles/lib_http_src2_exe.dir/request.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib_http_src2_exe.dir/request.cpp.s"
	cd /Users/ning/Interview-cpp/Http/cmake-build-debug/lib_http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Interview-cpp/Http/lib_http/request.cpp -o CMakeFiles/lib_http_src2_exe.dir/request.cpp.s

lib_http/CMakeFiles/lib_http_src2_exe.dir/request.cpp.o.requires:

.PHONY : lib_http/CMakeFiles/lib_http_src2_exe.dir/request.cpp.o.requires

lib_http/CMakeFiles/lib_http_src2_exe.dir/request.cpp.o.provides: lib_http/CMakeFiles/lib_http_src2_exe.dir/request.cpp.o.requires
	$(MAKE) -f lib_http/CMakeFiles/lib_http_src2_exe.dir/build.make lib_http/CMakeFiles/lib_http_src2_exe.dir/request.cpp.o.provides.build
.PHONY : lib_http/CMakeFiles/lib_http_src2_exe.dir/request.cpp.o.provides

lib_http/CMakeFiles/lib_http_src2_exe.dir/request.cpp.o.provides.build: lib_http/CMakeFiles/lib_http_src2_exe.dir/request.cpp.o


lib_http/CMakeFiles/lib_http_src2_exe.dir/response.cpp.o: lib_http/CMakeFiles/lib_http_src2_exe.dir/flags.make
lib_http/CMakeFiles/lib_http_src2_exe.dir/response.cpp.o: ../lib_http/response.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Interview-cpp/Http/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object lib_http/CMakeFiles/lib_http_src2_exe.dir/response.cpp.o"
	cd /Users/ning/Interview-cpp/Http/cmake-build-debug/lib_http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lib_http_src2_exe.dir/response.cpp.o -c /Users/ning/Interview-cpp/Http/lib_http/response.cpp

lib_http/CMakeFiles/lib_http_src2_exe.dir/response.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib_http_src2_exe.dir/response.cpp.i"
	cd /Users/ning/Interview-cpp/Http/cmake-build-debug/lib_http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Interview-cpp/Http/lib_http/response.cpp > CMakeFiles/lib_http_src2_exe.dir/response.cpp.i

lib_http/CMakeFiles/lib_http_src2_exe.dir/response.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib_http_src2_exe.dir/response.cpp.s"
	cd /Users/ning/Interview-cpp/Http/cmake-build-debug/lib_http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Interview-cpp/Http/lib_http/response.cpp -o CMakeFiles/lib_http_src2_exe.dir/response.cpp.s

lib_http/CMakeFiles/lib_http_src2_exe.dir/response.cpp.o.requires:

.PHONY : lib_http/CMakeFiles/lib_http_src2_exe.dir/response.cpp.o.requires

lib_http/CMakeFiles/lib_http_src2_exe.dir/response.cpp.o.provides: lib_http/CMakeFiles/lib_http_src2_exe.dir/response.cpp.o.requires
	$(MAKE) -f lib_http/CMakeFiles/lib_http_src2_exe.dir/build.make lib_http/CMakeFiles/lib_http_src2_exe.dir/response.cpp.o.provides.build
.PHONY : lib_http/CMakeFiles/lib_http_src2_exe.dir/response.cpp.o.provides

lib_http/CMakeFiles/lib_http_src2_exe.dir/response.cpp.o.provides.build: lib_http/CMakeFiles/lib_http_src2_exe.dir/response.cpp.o


lib_http/CMakeFiles/lib_http_src2_exe.dir/utils.cpp.o: lib_http/CMakeFiles/lib_http_src2_exe.dir/flags.make
lib_http/CMakeFiles/lib_http_src2_exe.dir/utils.cpp.o: ../lib_http/utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Interview-cpp/Http/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object lib_http/CMakeFiles/lib_http_src2_exe.dir/utils.cpp.o"
	cd /Users/ning/Interview-cpp/Http/cmake-build-debug/lib_http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lib_http_src2_exe.dir/utils.cpp.o -c /Users/ning/Interview-cpp/Http/lib_http/utils.cpp

lib_http/CMakeFiles/lib_http_src2_exe.dir/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib_http_src2_exe.dir/utils.cpp.i"
	cd /Users/ning/Interview-cpp/Http/cmake-build-debug/lib_http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Interview-cpp/Http/lib_http/utils.cpp > CMakeFiles/lib_http_src2_exe.dir/utils.cpp.i

lib_http/CMakeFiles/lib_http_src2_exe.dir/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib_http_src2_exe.dir/utils.cpp.s"
	cd /Users/ning/Interview-cpp/Http/cmake-build-debug/lib_http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Interview-cpp/Http/lib_http/utils.cpp -o CMakeFiles/lib_http_src2_exe.dir/utils.cpp.s

lib_http/CMakeFiles/lib_http_src2_exe.dir/utils.cpp.o.requires:

.PHONY : lib_http/CMakeFiles/lib_http_src2_exe.dir/utils.cpp.o.requires

lib_http/CMakeFiles/lib_http_src2_exe.dir/utils.cpp.o.provides: lib_http/CMakeFiles/lib_http_src2_exe.dir/utils.cpp.o.requires
	$(MAKE) -f lib_http/CMakeFiles/lib_http_src2_exe.dir/build.make lib_http/CMakeFiles/lib_http_src2_exe.dir/utils.cpp.o.provides.build
.PHONY : lib_http/CMakeFiles/lib_http_src2_exe.dir/utils.cpp.o.provides

lib_http/CMakeFiles/lib_http_src2_exe.dir/utils.cpp.o.provides.build: lib_http/CMakeFiles/lib_http_src2_exe.dir/utils.cpp.o


lib_http/CMakeFiles/lib_http_src2_exe.dir/websocket.cpp.o: lib_http/CMakeFiles/lib_http_src2_exe.dir/flags.make
lib_http/CMakeFiles/lib_http_src2_exe.dir/websocket.cpp.o: ../lib_http/websocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Interview-cpp/Http/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object lib_http/CMakeFiles/lib_http_src2_exe.dir/websocket.cpp.o"
	cd /Users/ning/Interview-cpp/Http/cmake-build-debug/lib_http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lib_http_src2_exe.dir/websocket.cpp.o -c /Users/ning/Interview-cpp/Http/lib_http/websocket.cpp

lib_http/CMakeFiles/lib_http_src2_exe.dir/websocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib_http_src2_exe.dir/websocket.cpp.i"
	cd /Users/ning/Interview-cpp/Http/cmake-build-debug/lib_http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Interview-cpp/Http/lib_http/websocket.cpp > CMakeFiles/lib_http_src2_exe.dir/websocket.cpp.i

lib_http/CMakeFiles/lib_http_src2_exe.dir/websocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib_http_src2_exe.dir/websocket.cpp.s"
	cd /Users/ning/Interview-cpp/Http/cmake-build-debug/lib_http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Interview-cpp/Http/lib_http/websocket.cpp -o CMakeFiles/lib_http_src2_exe.dir/websocket.cpp.s

lib_http/CMakeFiles/lib_http_src2_exe.dir/websocket.cpp.o.requires:

.PHONY : lib_http/CMakeFiles/lib_http_src2_exe.dir/websocket.cpp.o.requires

lib_http/CMakeFiles/lib_http_src2_exe.dir/websocket.cpp.o.provides: lib_http/CMakeFiles/lib_http_src2_exe.dir/websocket.cpp.o.requires
	$(MAKE) -f lib_http/CMakeFiles/lib_http_src2_exe.dir/build.make lib_http/CMakeFiles/lib_http_src2_exe.dir/websocket.cpp.o.provides.build
.PHONY : lib_http/CMakeFiles/lib_http_src2_exe.dir/websocket.cpp.o.provides

lib_http/CMakeFiles/lib_http_src2_exe.dir/websocket.cpp.o.provides.build: lib_http/CMakeFiles/lib_http_src2_exe.dir/websocket.cpp.o


# Object files for target lib_http_src2_exe
lib_http_src2_exe_OBJECTS = \
"CMakeFiles/lib_http_src2_exe.dir/http_server.cpp.o" \
"CMakeFiles/lib_http_src2_exe.dir/http_parser.cpp.o" \
"CMakeFiles/lib_http_src2_exe.dir/io_service_pool.cpp.o" \
"CMakeFiles/lib_http_src2_exe.dir/mime_type.cpp.o" \
"CMakeFiles/lib_http_src2_exe.dir/multipart_parser.cpp.o" \
"CMakeFiles/lib_http_src2_exe.dir/picohttpparser.cpp.o" \
"CMakeFiles/lib_http_src2_exe.dir/request.cpp.o" \
"CMakeFiles/lib_http_src2_exe.dir/response.cpp.o" \
"CMakeFiles/lib_http_src2_exe.dir/utils.cpp.o" \
"CMakeFiles/lib_http_src2_exe.dir/websocket.cpp.o"

# External object files for target lib_http_src2_exe
lib_http_src2_exe_EXTERNAL_OBJECTS =

lib_http/lib_http_src2_exe: lib_http/CMakeFiles/lib_http_src2_exe.dir/http_server.cpp.o
lib_http/lib_http_src2_exe: lib_http/CMakeFiles/lib_http_src2_exe.dir/http_parser.cpp.o
lib_http/lib_http_src2_exe: lib_http/CMakeFiles/lib_http_src2_exe.dir/io_service_pool.cpp.o
lib_http/lib_http_src2_exe: lib_http/CMakeFiles/lib_http_src2_exe.dir/mime_type.cpp.o
lib_http/lib_http_src2_exe: lib_http/CMakeFiles/lib_http_src2_exe.dir/multipart_parser.cpp.o
lib_http/lib_http_src2_exe: lib_http/CMakeFiles/lib_http_src2_exe.dir/picohttpparser.cpp.o
lib_http/lib_http_src2_exe: lib_http/CMakeFiles/lib_http_src2_exe.dir/request.cpp.o
lib_http/lib_http_src2_exe: lib_http/CMakeFiles/lib_http_src2_exe.dir/response.cpp.o
lib_http/lib_http_src2_exe: lib_http/CMakeFiles/lib_http_src2_exe.dir/utils.cpp.o
lib_http/lib_http_src2_exe: lib_http/CMakeFiles/lib_http_src2_exe.dir/websocket.cpp.o
lib_http/lib_http_src2_exe: lib_http/CMakeFiles/lib_http_src2_exe.dir/build.make
lib_http/lib_http_src2_exe: lib_http/CMakeFiles/lib_http_src2_exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ning/Interview-cpp/Http/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable lib_http_src2_exe"
	cd /Users/ning/Interview-cpp/Http/cmake-build-debug/lib_http && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lib_http_src2_exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib_http/CMakeFiles/lib_http_src2_exe.dir/build: lib_http/lib_http_src2_exe

.PHONY : lib_http/CMakeFiles/lib_http_src2_exe.dir/build

lib_http/CMakeFiles/lib_http_src2_exe.dir/requires: lib_http/CMakeFiles/lib_http_src2_exe.dir/http_server.cpp.o.requires
lib_http/CMakeFiles/lib_http_src2_exe.dir/requires: lib_http/CMakeFiles/lib_http_src2_exe.dir/http_parser.cpp.o.requires
lib_http/CMakeFiles/lib_http_src2_exe.dir/requires: lib_http/CMakeFiles/lib_http_src2_exe.dir/io_service_pool.cpp.o.requires
lib_http/CMakeFiles/lib_http_src2_exe.dir/requires: lib_http/CMakeFiles/lib_http_src2_exe.dir/mime_type.cpp.o.requires
lib_http/CMakeFiles/lib_http_src2_exe.dir/requires: lib_http/CMakeFiles/lib_http_src2_exe.dir/multipart_parser.cpp.o.requires
lib_http/CMakeFiles/lib_http_src2_exe.dir/requires: lib_http/CMakeFiles/lib_http_src2_exe.dir/picohttpparser.cpp.o.requires
lib_http/CMakeFiles/lib_http_src2_exe.dir/requires: lib_http/CMakeFiles/lib_http_src2_exe.dir/request.cpp.o.requires
lib_http/CMakeFiles/lib_http_src2_exe.dir/requires: lib_http/CMakeFiles/lib_http_src2_exe.dir/response.cpp.o.requires
lib_http/CMakeFiles/lib_http_src2_exe.dir/requires: lib_http/CMakeFiles/lib_http_src2_exe.dir/utils.cpp.o.requires
lib_http/CMakeFiles/lib_http_src2_exe.dir/requires: lib_http/CMakeFiles/lib_http_src2_exe.dir/websocket.cpp.o.requires

.PHONY : lib_http/CMakeFiles/lib_http_src2_exe.dir/requires

lib_http/CMakeFiles/lib_http_src2_exe.dir/clean:
	cd /Users/ning/Interview-cpp/Http/cmake-build-debug/lib_http && $(CMAKE_COMMAND) -P CMakeFiles/lib_http_src2_exe.dir/cmake_clean.cmake
.PHONY : lib_http/CMakeFiles/lib_http_src2_exe.dir/clean

lib_http/CMakeFiles/lib_http_src2_exe.dir/depend:
	cd /Users/ning/Interview-cpp/Http/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ning/Interview-cpp/Http /Users/ning/Interview-cpp/Http/lib_http /Users/ning/Interview-cpp/Http/cmake-build-debug /Users/ning/Interview-cpp/Http/cmake-build-debug/lib_http /Users/ning/Interview-cpp/Http/cmake-build-debug/lib_http/CMakeFiles/lib_http_src2_exe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib_http/CMakeFiles/lib_http_src2_exe.dir/depend

