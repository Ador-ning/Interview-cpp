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
include Http/lib_http/http/CMakeFiles/lib_http_src1_exe.dir/depend.make

# Include the progress variables for this target.
include Http/lib_http/http/CMakeFiles/lib_http_src1_exe.dir/progress.make

# Include the compile flags for this target's objects.
include Http/lib_http/http/CMakeFiles/lib_http_src1_exe.dir/flags.make

Http/lib_http/http/CMakeFiles/lib_http_src1_exe.dir/connection.cpp.o: Http/lib_http/http/CMakeFiles/lib_http_src1_exe.dir/flags.make
Http/lib_http/http/CMakeFiles/lib_http_src1_exe.dir/connection.cpp.o: ../Http/lib_http/http/connection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Interview-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Http/lib_http/http/CMakeFiles/lib_http_src1_exe.dir/connection.cpp.o"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http/lib_http/http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lib_http_src1_exe.dir/connection.cpp.o -c /Users/ning/Interview-cpp/Http/lib_http/http/connection.cpp

Http/lib_http/http/CMakeFiles/lib_http_src1_exe.dir/connection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib_http_src1_exe.dir/connection.cpp.i"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http/lib_http/http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Interview-cpp/Http/lib_http/http/connection.cpp > CMakeFiles/lib_http_src1_exe.dir/connection.cpp.i

Http/lib_http/http/CMakeFiles/lib_http_src1_exe.dir/connection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib_http_src1_exe.dir/connection.cpp.s"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http/lib_http/http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Interview-cpp/Http/lib_http/http/connection.cpp -o CMakeFiles/lib_http_src1_exe.dir/connection.cpp.s

Http/lib_http/http/CMakeFiles/lib_http_src1_exe.dir/connection.cpp.o.requires:

.PHONY : Http/lib_http/http/CMakeFiles/lib_http_src1_exe.dir/connection.cpp.o.requires

Http/lib_http/http/CMakeFiles/lib_http_src1_exe.dir/connection.cpp.o.provides: Http/lib_http/http/CMakeFiles/lib_http_src1_exe.dir/connection.cpp.o.requires
	$(MAKE) -f Http/lib_http/http/CMakeFiles/lib_http_src1_exe.dir/build.make Http/lib_http/http/CMakeFiles/lib_http_src1_exe.dir/connection.cpp.o.provides.build
.PHONY : Http/lib_http/http/CMakeFiles/lib_http_src1_exe.dir/connection.cpp.o.provides

Http/lib_http/http/CMakeFiles/lib_http_src1_exe.dir/connection.cpp.o.provides.build: Http/lib_http/http/CMakeFiles/lib_http_src1_exe.dir/connection.cpp.o


# Object files for target lib_http_src1_exe
lib_http_src1_exe_OBJECTS = \
"CMakeFiles/lib_http_src1_exe.dir/connection.cpp.o"

# External object files for target lib_http_src1_exe
lib_http_src1_exe_EXTERNAL_OBJECTS =

Http/lib_http/http/lib_http_src1_exe: Http/lib_http/http/CMakeFiles/lib_http_src1_exe.dir/connection.cpp.o
Http/lib_http/http/lib_http_src1_exe: Http/lib_http/http/CMakeFiles/lib_http_src1_exe.dir/build.make
Http/lib_http/http/lib_http_src1_exe: Http/lib_http/http/CMakeFiles/lib_http_src1_exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ning/Interview-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lib_http_src1_exe"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http/lib_http/http && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lib_http_src1_exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Http/lib_http/http/CMakeFiles/lib_http_src1_exe.dir/build: Http/lib_http/http/lib_http_src1_exe

.PHONY : Http/lib_http/http/CMakeFiles/lib_http_src1_exe.dir/build

Http/lib_http/http/CMakeFiles/lib_http_src1_exe.dir/requires: Http/lib_http/http/CMakeFiles/lib_http_src1_exe.dir/connection.cpp.o.requires

.PHONY : Http/lib_http/http/CMakeFiles/lib_http_src1_exe.dir/requires

Http/lib_http/http/CMakeFiles/lib_http_src1_exe.dir/clean:
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http/lib_http/http && $(CMAKE_COMMAND) -P CMakeFiles/lib_http_src1_exe.dir/cmake_clean.cmake
.PHONY : Http/lib_http/http/CMakeFiles/lib_http_src1_exe.dir/clean

Http/lib_http/http/CMakeFiles/lib_http_src1_exe.dir/depend:
	cd /Users/ning/Interview-cpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ning/Interview-cpp /Users/ning/Interview-cpp/Http/lib_http/http /Users/ning/Interview-cpp/cmake-build-debug /Users/ning/Interview-cpp/cmake-build-debug/Http/lib_http/http /Users/ning/Interview-cpp/cmake-build-debug/Http/lib_http/http/CMakeFiles/lib_http_src1_exe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Http/lib_http/http/CMakeFiles/lib_http_src1_exe.dir/depend

