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
include Concurrent/CMakeFiles/thread_test.dir/depend.make

# Include the progress variables for this target.
include Concurrent/CMakeFiles/thread_test.dir/progress.make

# Include the compile flags for this target's objects.
include Concurrent/CMakeFiles/thread_test.dir/flags.make

Concurrent/CMakeFiles/thread_test.dir/test.cpp.o: Concurrent/CMakeFiles/thread_test.dir/flags.make
Concurrent/CMakeFiles/thread_test.dir/test.cpp.o: ../Concurrent/test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Interview-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Concurrent/CMakeFiles/thread_test.dir/test.cpp.o"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Concurrent && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/thread_test.dir/test.cpp.o -c /Users/ning/Interview-cpp/Concurrent/test.cpp

Concurrent/CMakeFiles/thread_test.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/thread_test.dir/test.cpp.i"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Concurrent && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Interview-cpp/Concurrent/test.cpp > CMakeFiles/thread_test.dir/test.cpp.i

Concurrent/CMakeFiles/thread_test.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/thread_test.dir/test.cpp.s"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Concurrent && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Interview-cpp/Concurrent/test.cpp -o CMakeFiles/thread_test.dir/test.cpp.s

Concurrent/CMakeFiles/thread_test.dir/test.cpp.o.requires:

.PHONY : Concurrent/CMakeFiles/thread_test.dir/test.cpp.o.requires

Concurrent/CMakeFiles/thread_test.dir/test.cpp.o.provides: Concurrent/CMakeFiles/thread_test.dir/test.cpp.o.requires
	$(MAKE) -f Concurrent/CMakeFiles/thread_test.dir/build.make Concurrent/CMakeFiles/thread_test.dir/test.cpp.o.provides.build
.PHONY : Concurrent/CMakeFiles/thread_test.dir/test.cpp.o.provides

Concurrent/CMakeFiles/thread_test.dir/test.cpp.o.provides.build: Concurrent/CMakeFiles/thread_test.dir/test.cpp.o


# Object files for target thread_test
thread_test_OBJECTS = \
"CMakeFiles/thread_test.dir/test.cpp.o"

# External object files for target thread_test
thread_test_EXTERNAL_OBJECTS =

Concurrent/thread_test: Concurrent/CMakeFiles/thread_test.dir/test.cpp.o
Concurrent/thread_test: Concurrent/CMakeFiles/thread_test.dir/build.make
Concurrent/thread_test: Concurrent/CMakeFiles/thread_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ning/Interview-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable thread_test"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Concurrent && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/thread_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Concurrent/CMakeFiles/thread_test.dir/build: Concurrent/thread_test

.PHONY : Concurrent/CMakeFiles/thread_test.dir/build

Concurrent/CMakeFiles/thread_test.dir/requires: Concurrent/CMakeFiles/thread_test.dir/test.cpp.o.requires

.PHONY : Concurrent/CMakeFiles/thread_test.dir/requires

Concurrent/CMakeFiles/thread_test.dir/clean:
	cd /Users/ning/Interview-cpp/cmake-build-debug/Concurrent && $(CMAKE_COMMAND) -P CMakeFiles/thread_test.dir/cmake_clean.cmake
.PHONY : Concurrent/CMakeFiles/thread_test.dir/clean

Concurrent/CMakeFiles/thread_test.dir/depend:
	cd /Users/ning/Interview-cpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ning/Interview-cpp /Users/ning/Interview-cpp/Concurrent /Users/ning/Interview-cpp/cmake-build-debug /Users/ning/Interview-cpp/cmake-build-debug/Concurrent /Users/ning/Interview-cpp/cmake-build-debug/Concurrent/CMakeFiles/thread_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Concurrent/CMakeFiles/thread_test.dir/depend

