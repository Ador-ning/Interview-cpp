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
CMAKE_SOURCE_DIR = /Users/ning/Interview-cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ning/Interview-cpp/cmake-build-debug

# Include any dependencies generated for this target.
include Http/CMakeFiles/http_examples.dir/depend.make

# Include the progress variables for this target.
include Http/CMakeFiles/http_examples.dir/progress.make

# Include the compile flags for this target's objects.
include Http/CMakeFiles/http_examples.dir/flags.make

Http/CMakeFiles/http_examples.dir/examples/main.cpp.o: Http/CMakeFiles/http_examples.dir/flags.make
Http/CMakeFiles/http_examples.dir/examples/main.cpp.o: ../Http/examples/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Interview-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Http/CMakeFiles/http_examples.dir/examples/main.cpp.o"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/http_examples.dir/examples/main.cpp.o -c /Users/ning/Interview-cpp/Http/examples/main.cpp

Http/CMakeFiles/http_examples.dir/examples/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/http_examples.dir/examples/main.cpp.i"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Interview-cpp/Http/examples/main.cpp > CMakeFiles/http_examples.dir/examples/main.cpp.i

Http/CMakeFiles/http_examples.dir/examples/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/http_examples.dir/examples/main.cpp.s"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Interview-cpp/Http/examples/main.cpp -o CMakeFiles/http_examples.dir/examples/main.cpp.s

Http/CMakeFiles/http_examples.dir/examples/main.cpp.o.requires:

.PHONY : Http/CMakeFiles/http_examples.dir/examples/main.cpp.o.requires

Http/CMakeFiles/http_examples.dir/examples/main.cpp.o.provides: Http/CMakeFiles/http_examples.dir/examples/main.cpp.o.requires
	$(MAKE) -f Http/CMakeFiles/http_examples.dir/build.make Http/CMakeFiles/http_examples.dir/examples/main.cpp.o.provides.build
.PHONY : Http/CMakeFiles/http_examples.dir/examples/main.cpp.o.provides

Http/CMakeFiles/http_examples.dir/examples/main.cpp.o.provides.build: Http/CMakeFiles/http_examples.dir/examples/main.cpp.o


# Object files for target http_examples
http_examples_OBJECTS = \
"CMakeFiles/http_examples.dir/examples/main.cpp.o"

# External object files for target http_examples
http_examples_EXTERNAL_OBJECTS =

Http/http_examples: Http/CMakeFiles/http_examples.dir/examples/main.cpp.o
Http/http_examples: Http/CMakeFiles/http_examples.dir/build.make
Http/http_examples: Http/liblib.a
Http/http_examples: Http/libhttp_lib.a
Http/http_examples: /usr/local/lib/libboost_coroutine-mt.dylib
Http/http_examples: /usr/local/lib/libboost_context-mt.dylib
Http/http_examples: /usr/local/lib/libboost_system-mt.dylib
Http/http_examples: /usr/local/lib/libboost_thread-mt.dylib
Http/http_examples: /usr/local/lib/libboost_filesystem-mt.dylib
Http/http_examples: /usr/local/lib/libboost_chrono-mt.dylib
Http/http_examples: /usr/local/lib/libboost_date_time-mt.dylib
Http/http_examples: /usr/local/lib/libboost_atomic-mt.dylib
Http/http_examples: /usr/lib/libssl.dylib
Http/http_examples: /usr/lib/libcrypto.dylib
Http/http_examples: Http/CMakeFiles/http_examples.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ning/Interview-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable http_examples"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/http_examples.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Http/CMakeFiles/http_examples.dir/build: Http/http_examples

.PHONY : Http/CMakeFiles/http_examples.dir/build

Http/CMakeFiles/http_examples.dir/requires: Http/CMakeFiles/http_examples.dir/examples/main.cpp.o.requires

.PHONY : Http/CMakeFiles/http_examples.dir/requires

Http/CMakeFiles/http_examples.dir/clean:
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http && $(CMAKE_COMMAND) -P CMakeFiles/http_examples.dir/cmake_clean.cmake
.PHONY : Http/CMakeFiles/http_examples.dir/clean

Http/CMakeFiles/http_examples.dir/depend:
	cd /Users/ning/Interview-cpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ning/Interview-cpp /Users/ning/Interview-cpp/Http /Users/ning/Interview-cpp/cmake-build-debug /Users/ning/Interview-cpp/cmake-build-debug/Http /Users/ning/Interview-cpp/cmake-build-debug/Http/CMakeFiles/http_examples.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Http/CMakeFiles/http_examples.dir/depend

