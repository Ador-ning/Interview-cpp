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
include JSON/tutorial01/CMakeFiles/leptjson.dir/depend.make

# Include the progress variables for this target.
include JSON/tutorial01/CMakeFiles/leptjson.dir/progress.make

# Include the compile flags for this target's objects.
include JSON/tutorial01/CMakeFiles/leptjson.dir/flags.make

JSON/tutorial01/CMakeFiles/leptjson.dir/leptjson.c.o: JSON/tutorial01/CMakeFiles/leptjson.dir/flags.make
JSON/tutorial01/CMakeFiles/leptjson.dir/leptjson.c.o: ../JSON/tutorial01/leptjson.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Interview-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object JSON/tutorial01/CMakeFiles/leptjson.dir/leptjson.c.o"
	cd /Users/ning/Interview-cpp/cmake-build-debug/JSON/tutorial01 && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/leptjson.dir/leptjson.c.o   -c /Users/ning/Interview-cpp/JSON/tutorial01/leptjson.c

JSON/tutorial01/CMakeFiles/leptjson.dir/leptjson.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/leptjson.dir/leptjson.c.i"
	cd /Users/ning/Interview-cpp/cmake-build-debug/JSON/tutorial01 && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ning/Interview-cpp/JSON/tutorial01/leptjson.c > CMakeFiles/leptjson.dir/leptjson.c.i

JSON/tutorial01/CMakeFiles/leptjson.dir/leptjson.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/leptjson.dir/leptjson.c.s"
	cd /Users/ning/Interview-cpp/cmake-build-debug/JSON/tutorial01 && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ning/Interview-cpp/JSON/tutorial01/leptjson.c -o CMakeFiles/leptjson.dir/leptjson.c.s

JSON/tutorial01/CMakeFiles/leptjson.dir/leptjson.c.o.requires:

.PHONY : JSON/tutorial01/CMakeFiles/leptjson.dir/leptjson.c.o.requires

JSON/tutorial01/CMakeFiles/leptjson.dir/leptjson.c.o.provides: JSON/tutorial01/CMakeFiles/leptjson.dir/leptjson.c.o.requires
	$(MAKE) -f JSON/tutorial01/CMakeFiles/leptjson.dir/build.make JSON/tutorial01/CMakeFiles/leptjson.dir/leptjson.c.o.provides.build
.PHONY : JSON/tutorial01/CMakeFiles/leptjson.dir/leptjson.c.o.provides

JSON/tutorial01/CMakeFiles/leptjson.dir/leptjson.c.o.provides.build: JSON/tutorial01/CMakeFiles/leptjson.dir/leptjson.c.o


# Object files for target leptjson
leptjson_OBJECTS = \
"CMakeFiles/leptjson.dir/leptjson.c.o"

# External object files for target leptjson
leptjson_EXTERNAL_OBJECTS =

JSON/tutorial01/libleptjson.a: JSON/tutorial01/CMakeFiles/leptjson.dir/leptjson.c.o
JSON/tutorial01/libleptjson.a: JSON/tutorial01/CMakeFiles/leptjson.dir/build.make
JSON/tutorial01/libleptjson.a: JSON/tutorial01/CMakeFiles/leptjson.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ning/Interview-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libleptjson.a"
	cd /Users/ning/Interview-cpp/cmake-build-debug/JSON/tutorial01 && $(CMAKE_COMMAND) -P CMakeFiles/leptjson.dir/cmake_clean_target.cmake
	cd /Users/ning/Interview-cpp/cmake-build-debug/JSON/tutorial01 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/leptjson.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
JSON/tutorial01/CMakeFiles/leptjson.dir/build: JSON/tutorial01/libleptjson.a

.PHONY : JSON/tutorial01/CMakeFiles/leptjson.dir/build

JSON/tutorial01/CMakeFiles/leptjson.dir/requires: JSON/tutorial01/CMakeFiles/leptjson.dir/leptjson.c.o.requires

.PHONY : JSON/tutorial01/CMakeFiles/leptjson.dir/requires

JSON/tutorial01/CMakeFiles/leptjson.dir/clean:
	cd /Users/ning/Interview-cpp/cmake-build-debug/JSON/tutorial01 && $(CMAKE_COMMAND) -P CMakeFiles/leptjson.dir/cmake_clean.cmake
.PHONY : JSON/tutorial01/CMakeFiles/leptjson.dir/clean

JSON/tutorial01/CMakeFiles/leptjson.dir/depend:
	cd /Users/ning/Interview-cpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ning/Interview-cpp /Users/ning/Interview-cpp/JSON/tutorial01 /Users/ning/Interview-cpp/cmake-build-debug /Users/ning/Interview-cpp/cmake-build-debug/JSON/tutorial01 /Users/ning/Interview-cpp/cmake-build-debug/JSON/tutorial01/CMakeFiles/leptjson.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : JSON/tutorial01/CMakeFiles/leptjson.dir/depend
