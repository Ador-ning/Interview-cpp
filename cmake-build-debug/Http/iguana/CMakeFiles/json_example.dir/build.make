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
include Http/iguana/CMakeFiles/json_example.dir/depend.make

# Include the progress variables for this target.
include Http/iguana/CMakeFiles/json_example.dir/progress.make

# Include the compile flags for this target's objects.
include Http/iguana/CMakeFiles/json_example.dir/flags.make

Http/iguana/CMakeFiles/json_example.dir/example/json_example.cpp.o: Http/iguana/CMakeFiles/json_example.dir/flags.make
Http/iguana/CMakeFiles/json_example.dir/example/json_example.cpp.o: ../Http/iguana/example/json_example.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Interview-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Http/iguana/CMakeFiles/json_example.dir/example/json_example.cpp.o"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http/iguana && /usr/local/Cellar/gcc/8.1.0/bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/json_example.dir/example/json_example.cpp.o -c /Users/ning/Interview-cpp/Http/iguana/example/json_example.cpp

Http/iguana/CMakeFiles/json_example.dir/example/json_example.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/json_example.dir/example/json_example.cpp.i"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http/iguana && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Interview-cpp/Http/iguana/example/json_example.cpp > CMakeFiles/json_example.dir/example/json_example.cpp.i

Http/iguana/CMakeFiles/json_example.dir/example/json_example.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/json_example.dir/example/json_example.cpp.s"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http/iguana && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Interview-cpp/Http/iguana/example/json_example.cpp -o CMakeFiles/json_example.dir/example/json_example.cpp.s

Http/iguana/CMakeFiles/json_example.dir/example/json_example.cpp.o.requires:

.PHONY : Http/iguana/CMakeFiles/json_example.dir/example/json_example.cpp.o.requires

Http/iguana/CMakeFiles/json_example.dir/example/json_example.cpp.o.provides: Http/iguana/CMakeFiles/json_example.dir/example/json_example.cpp.o.requires
	$(MAKE) -f Http/iguana/CMakeFiles/json_example.dir/build.make Http/iguana/CMakeFiles/json_example.dir/example/json_example.cpp.o.provides.build
.PHONY : Http/iguana/CMakeFiles/json_example.dir/example/json_example.cpp.o.provides

Http/iguana/CMakeFiles/json_example.dir/example/json_example.cpp.o.provides.build: Http/iguana/CMakeFiles/json_example.dir/example/json_example.cpp.o


# Object files for target json_example
json_example_OBJECTS = \
"CMakeFiles/json_example.dir/example/json_example.cpp.o"

# External object files for target json_example
json_example_EXTERNAL_OBJECTS =

Http/iguana/json_example: Http/iguana/CMakeFiles/json_example.dir/example/json_example.cpp.o
Http/iguana/json_example: Http/iguana/CMakeFiles/json_example.dir/build.make
Http/iguana/json_example: Http/iguana/CMakeFiles/json_example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ning/Interview-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable json_example"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http/iguana && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/json_example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Http/iguana/CMakeFiles/json_example.dir/build: Http/iguana/json_example

.PHONY : Http/iguana/CMakeFiles/json_example.dir/build

Http/iguana/CMakeFiles/json_example.dir/requires: Http/iguana/CMakeFiles/json_example.dir/example/json_example.cpp.o.requires

.PHONY : Http/iguana/CMakeFiles/json_example.dir/requires

Http/iguana/CMakeFiles/json_example.dir/clean:
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http/iguana && $(CMAKE_COMMAND) -P CMakeFiles/json_example.dir/cmake_clean.cmake
.PHONY : Http/iguana/CMakeFiles/json_example.dir/clean

Http/iguana/CMakeFiles/json_example.dir/depend:
	cd /Users/ning/Interview-cpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ning/Interview-cpp /Users/ning/Interview-cpp/Http/iguana /Users/ning/Interview-cpp/cmake-build-debug /Users/ning/Interview-cpp/cmake-build-debug/Http/iguana /Users/ning/Interview-cpp/cmake-build-debug/Http/iguana/CMakeFiles/json_example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Http/iguana/CMakeFiles/json_example.dir/depend

