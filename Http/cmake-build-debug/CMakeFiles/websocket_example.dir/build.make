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
include CMakeFiles/websocket_example.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/websocket_example.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/websocket_example.dir/flags.make

CMakeFiles/websocket_example.dir/examples/websocket.cpp.o: CMakeFiles/websocket_example.dir/flags.make
CMakeFiles/websocket_example.dir/examples/websocket.cpp.o: ../examples/websocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Interview-cpp/Http/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/websocket_example.dir/examples/websocket.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/websocket_example.dir/examples/websocket.cpp.o -c /Users/ning/Interview-cpp/Http/examples/websocket.cpp

CMakeFiles/websocket_example.dir/examples/websocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/websocket_example.dir/examples/websocket.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Interview-cpp/Http/examples/websocket.cpp > CMakeFiles/websocket_example.dir/examples/websocket.cpp.i

CMakeFiles/websocket_example.dir/examples/websocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/websocket_example.dir/examples/websocket.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Interview-cpp/Http/examples/websocket.cpp -o CMakeFiles/websocket_example.dir/examples/websocket.cpp.s

CMakeFiles/websocket_example.dir/examples/websocket.cpp.o.requires:

.PHONY : CMakeFiles/websocket_example.dir/examples/websocket.cpp.o.requires

CMakeFiles/websocket_example.dir/examples/websocket.cpp.o.provides: CMakeFiles/websocket_example.dir/examples/websocket.cpp.o.requires
	$(MAKE) -f CMakeFiles/websocket_example.dir/build.make CMakeFiles/websocket_example.dir/examples/websocket.cpp.o.provides.build
.PHONY : CMakeFiles/websocket_example.dir/examples/websocket.cpp.o.provides

CMakeFiles/websocket_example.dir/examples/websocket.cpp.o.provides.build: CMakeFiles/websocket_example.dir/examples/websocket.cpp.o


# Object files for target websocket_example
websocket_example_OBJECTS = \
"CMakeFiles/websocket_example.dir/examples/websocket.cpp.o"

# External object files for target websocket_example
websocket_example_EXTERNAL_OBJECTS =

websocket_example: CMakeFiles/websocket_example.dir/examples/websocket.cpp.o
websocket_example: CMakeFiles/websocket_example.dir/build.make
websocket_example: liblib.a
websocket_example: /usr/local/lib/libboost_coroutine-mt.dylib
websocket_example: /usr/local/lib/libboost_context-mt.dylib
websocket_example: /usr/local/lib/libboost_system-mt.dylib
websocket_example: /usr/local/lib/libboost_thread-mt.dylib
websocket_example: /usr/local/lib/libboost_filesystem-mt.dylib
websocket_example: /usr/local/lib/libboost_chrono-mt.dylib
websocket_example: /usr/local/lib/libboost_date_time-mt.dylib
websocket_example: /usr/local/lib/libboost_atomic-mt.dylib
websocket_example: /usr/lib/libssl.dylib
websocket_example: /usr/lib/libcrypto.dylib
websocket_example: CMakeFiles/websocket_example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ning/Interview-cpp/Http/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable websocket_example"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/websocket_example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/websocket_example.dir/build: websocket_example

.PHONY : CMakeFiles/websocket_example.dir/build

CMakeFiles/websocket_example.dir/requires: CMakeFiles/websocket_example.dir/examples/websocket.cpp.o.requires

.PHONY : CMakeFiles/websocket_example.dir/requires

CMakeFiles/websocket_example.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/websocket_example.dir/cmake_clean.cmake
.PHONY : CMakeFiles/websocket_example.dir/clean

CMakeFiles/websocket_example.dir/depend:
	cd /Users/ning/Interview-cpp/Http/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ning/Interview-cpp/Http /Users/ning/Interview-cpp/Http /Users/ning/Interview-cpp/Http/cmake-build-debug /Users/ning/Interview-cpp/Http/cmake-build-debug /Users/ning/Interview-cpp/Http/cmake-build-debug/CMakeFiles/websocket_example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/websocket_example.dir/depend

