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
include Http/CMakeFiles/file_example.dir/depend.make

# Include the progress variables for this target.
include Http/CMakeFiles/file_example.dir/progress.make

# Include the compile flags for this target's objects.
include Http/CMakeFiles/file_example.dir/flags.make

Http/CMakeFiles/file_example.dir/examples/file_manager.cpp.o: Http/CMakeFiles/file_example.dir/flags.make
Http/CMakeFiles/file_example.dir/examples/file_manager.cpp.o: ../Http/examples/file_manager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Interview-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Http/CMakeFiles/file_example.dir/examples/file_manager.cpp.o"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/file_example.dir/examples/file_manager.cpp.o -c /Users/ning/Interview-cpp/Http/examples/file_manager.cpp

Http/CMakeFiles/file_example.dir/examples/file_manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/file_example.dir/examples/file_manager.cpp.i"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Interview-cpp/Http/examples/file_manager.cpp > CMakeFiles/file_example.dir/examples/file_manager.cpp.i

Http/CMakeFiles/file_example.dir/examples/file_manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/file_example.dir/examples/file_manager.cpp.s"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Interview-cpp/Http/examples/file_manager.cpp -o CMakeFiles/file_example.dir/examples/file_manager.cpp.s

Http/CMakeFiles/file_example.dir/examples/file_manager.cpp.o.requires:

.PHONY : Http/CMakeFiles/file_example.dir/examples/file_manager.cpp.o.requires

Http/CMakeFiles/file_example.dir/examples/file_manager.cpp.o.provides: Http/CMakeFiles/file_example.dir/examples/file_manager.cpp.o.requires
	$(MAKE) -f Http/CMakeFiles/file_example.dir/build.make Http/CMakeFiles/file_example.dir/examples/file_manager.cpp.o.provides.build
.PHONY : Http/CMakeFiles/file_example.dir/examples/file_manager.cpp.o.provides

Http/CMakeFiles/file_example.dir/examples/file_manager.cpp.o.provides.build: Http/CMakeFiles/file_example.dir/examples/file_manager.cpp.o


# Object files for target file_example
file_example_OBJECTS = \
"CMakeFiles/file_example.dir/examples/file_manager.cpp.o"

# External object files for target file_example
file_example_EXTERNAL_OBJECTS =

Http/file_example: Http/CMakeFiles/file_example.dir/examples/file_manager.cpp.o
Http/file_example: Http/CMakeFiles/file_example.dir/build.make
Http/file_example: Http/liblib.a
Http/file_example: Http/libhttp_lib.a
Http/file_example: /usr/local/lib/libboost_coroutine-mt.dylib
Http/file_example: /usr/local/lib/libboost_context-mt.dylib
Http/file_example: /usr/local/lib/libboost_system-mt.dylib
Http/file_example: /usr/local/lib/libboost_thread-mt.dylib
Http/file_example: /usr/local/lib/libboost_filesystem-mt.dylib
Http/file_example: /usr/local/lib/libboost_chrono-mt.dylib
Http/file_example: /usr/local/lib/libboost_date_time-mt.dylib
Http/file_example: /usr/local/lib/libboost_atomic-mt.dylib
Http/file_example: /usr/lib/libssl.dylib
Http/file_example: /usr/lib/libcrypto.dylib
Http/file_example: Http/CMakeFiles/file_example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ning/Interview-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable file_example"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/file_example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Http/CMakeFiles/file_example.dir/build: Http/file_example

.PHONY : Http/CMakeFiles/file_example.dir/build

Http/CMakeFiles/file_example.dir/requires: Http/CMakeFiles/file_example.dir/examples/file_manager.cpp.o.requires

.PHONY : Http/CMakeFiles/file_example.dir/requires

Http/CMakeFiles/file_example.dir/clean:
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http && $(CMAKE_COMMAND) -P CMakeFiles/file_example.dir/cmake_clean.cmake
.PHONY : Http/CMakeFiles/file_example.dir/clean

Http/CMakeFiles/file_example.dir/depend:
	cd /Users/ning/Interview-cpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ning/Interview-cpp /Users/ning/Interview-cpp/Http /Users/ning/Interview-cpp/cmake-build-debug /Users/ning/Interview-cpp/cmake-build-debug/Http /Users/ning/Interview-cpp/cmake-build-debug/Http/CMakeFiles/file_example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Http/CMakeFiles/file_example.dir/depend
