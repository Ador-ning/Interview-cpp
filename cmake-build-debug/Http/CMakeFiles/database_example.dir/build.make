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
include Http/CMakeFiles/database_example.dir/depend.make

# Include the progress variables for this target.
include Http/CMakeFiles/database_example.dir/progress.make

# Include the compile flags for this target's objects.
include Http/CMakeFiles/database_example.dir/flags.make

Http/CMakeFiles/database_example.dir/examples/database.cpp.o: Http/CMakeFiles/database_example.dir/flags.make
Http/CMakeFiles/database_example.dir/examples/database.cpp.o: ../Http/examples/database.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Interview-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Http/CMakeFiles/database_example.dir/examples/database.cpp.o"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/database_example.dir/examples/database.cpp.o -c /Users/ning/Interview-cpp/Http/examples/database.cpp

Http/CMakeFiles/database_example.dir/examples/database.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/database_example.dir/examples/database.cpp.i"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Interview-cpp/Http/examples/database.cpp > CMakeFiles/database_example.dir/examples/database.cpp.i

Http/CMakeFiles/database_example.dir/examples/database.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/database_example.dir/examples/database.cpp.s"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Interview-cpp/Http/examples/database.cpp -o CMakeFiles/database_example.dir/examples/database.cpp.s

Http/CMakeFiles/database_example.dir/examples/database.cpp.o.requires:

.PHONY : Http/CMakeFiles/database_example.dir/examples/database.cpp.o.requires

Http/CMakeFiles/database_example.dir/examples/database.cpp.o.provides: Http/CMakeFiles/database_example.dir/examples/database.cpp.o.requires
	$(MAKE) -f Http/CMakeFiles/database_example.dir/build.make Http/CMakeFiles/database_example.dir/examples/database.cpp.o.provides.build
.PHONY : Http/CMakeFiles/database_example.dir/examples/database.cpp.o.provides

Http/CMakeFiles/database_example.dir/examples/database.cpp.o.provides.build: Http/CMakeFiles/database_example.dir/examples/database.cpp.o


# Object files for target database_example
database_example_OBJECTS = \
"CMakeFiles/database_example.dir/examples/database.cpp.o"

# External object files for target database_example
database_example_EXTERNAL_OBJECTS =

Http/database_example: Http/CMakeFiles/database_example.dir/examples/database.cpp.o
Http/database_example: Http/CMakeFiles/database_example.dir/build.make
Http/database_example: Http/liblib.a
Http/database_example: Http/libhttp_lib.a
Http/database_example: /usr/local/lib/libboost_coroutine-mt.dylib
Http/database_example: /usr/local/lib/libboost_context-mt.dylib
Http/database_example: /usr/local/lib/libboost_system-mt.dylib
Http/database_example: /usr/local/lib/libboost_thread-mt.dylib
Http/database_example: /usr/local/lib/libboost_filesystem-mt.dylib
Http/database_example: /usr/local/lib/libboost_chrono-mt.dylib
Http/database_example: /usr/local/lib/libboost_date_time-mt.dylib
Http/database_example: /usr/local/lib/libboost_atomic-mt.dylib
Http/database_example: /usr/lib/libssl.dylib
Http/database_example: /usr/lib/libcrypto.dylib
Http/database_example: Http/CMakeFiles/database_example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ning/Interview-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable database_example"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/database_example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Http/CMakeFiles/database_example.dir/build: Http/database_example

.PHONY : Http/CMakeFiles/database_example.dir/build

Http/CMakeFiles/database_example.dir/requires: Http/CMakeFiles/database_example.dir/examples/database.cpp.o.requires

.PHONY : Http/CMakeFiles/database_example.dir/requires

Http/CMakeFiles/database_example.dir/clean:
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http && $(CMAKE_COMMAND) -P CMakeFiles/database_example.dir/cmake_clean.cmake
.PHONY : Http/CMakeFiles/database_example.dir/clean

Http/CMakeFiles/database_example.dir/depend:
	cd /Users/ning/Interview-cpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ning/Interview-cpp /Users/ning/Interview-cpp/Http /Users/ning/Interview-cpp/cmake-build-debug /Users/ning/Interview-cpp/cmake-build-debug/Http /Users/ning/Interview-cpp/cmake-build-debug/Http/CMakeFiles/database_example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Http/CMakeFiles/database_example.dir/depend

