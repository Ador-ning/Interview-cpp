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
include Http/CMakeFiles/lib.dir/depend.make

# Include the progress variables for this target.
include Http/CMakeFiles/lib.dir/progress.make

# Include the compile flags for this target's objects.
include Http/CMakeFiles/lib.dir/flags.make

# Object files for target lib
lib_OBJECTS =

# External object files for target lib
lib_EXTERNAL_OBJECTS =

Http/liblib.a: Http/CMakeFiles/lib.dir/build.make
Http/liblib.a: Http/CMakeFiles/lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ning/Interview-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Linking CXX static library liblib.a"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http && $(CMAKE_COMMAND) -P CMakeFiles/lib.dir/cmake_clean_target.cmake
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Http/CMakeFiles/lib.dir/build: Http/liblib.a

.PHONY : Http/CMakeFiles/lib.dir/build

Http/CMakeFiles/lib.dir/requires:

.PHONY : Http/CMakeFiles/lib.dir/requires

Http/CMakeFiles/lib.dir/clean:
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http && $(CMAKE_COMMAND) -P CMakeFiles/lib.dir/cmake_clean.cmake
.PHONY : Http/CMakeFiles/lib.dir/clean

Http/CMakeFiles/lib.dir/depend:
	cd /Users/ning/Interview-cpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ning/Interview-cpp /Users/ning/Interview-cpp/Http /Users/ning/Interview-cpp/cmake-build-debug /Users/ning/Interview-cpp/cmake-build-debug/Http /Users/ning/Interview-cpp/cmake-build-debug/Http/CMakeFiles/lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Http/CMakeFiles/lib.dir/depend

