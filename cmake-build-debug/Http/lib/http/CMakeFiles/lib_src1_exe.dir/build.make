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
include Http/lib/http/CMakeFiles/lib_src1_exe.dir/depend.make

# Include the progress variables for this target.
include Http/lib/http/CMakeFiles/lib_src1_exe.dir/progress.make

# Include the compile flags for this target's objects.
include Http/lib/http/CMakeFiles/lib_src1_exe.dir/flags.make

Http/lib/http/CMakeFiles/lib_src1_exe.dir/middleware/cookies.cpp.o: Http/lib/http/CMakeFiles/lib_src1_exe.dir/flags.make
Http/lib/http/CMakeFiles/lib_src1_exe.dir/middleware/cookies.cpp.o: ../Http/lib/http/middleware/cookies.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Interview-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Http/lib/http/CMakeFiles/lib_src1_exe.dir/middleware/cookies.cpp.o"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http/lib/http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lib_src1_exe.dir/middleware/cookies.cpp.o -c /Users/ning/Interview-cpp/Http/lib/http/middleware/cookies.cpp

Http/lib/http/CMakeFiles/lib_src1_exe.dir/middleware/cookies.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib_src1_exe.dir/middleware/cookies.cpp.i"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http/lib/http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Interview-cpp/Http/lib/http/middleware/cookies.cpp > CMakeFiles/lib_src1_exe.dir/middleware/cookies.cpp.i

Http/lib/http/CMakeFiles/lib_src1_exe.dir/middleware/cookies.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib_src1_exe.dir/middleware/cookies.cpp.s"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http/lib/http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Interview-cpp/Http/lib/http/middleware/cookies.cpp -o CMakeFiles/lib_src1_exe.dir/middleware/cookies.cpp.s

Http/lib/http/CMakeFiles/lib_src1_exe.dir/middleware/cookies.cpp.o.requires:

.PHONY : Http/lib/http/CMakeFiles/lib_src1_exe.dir/middleware/cookies.cpp.o.requires

Http/lib/http/CMakeFiles/lib_src1_exe.dir/middleware/cookies.cpp.o.provides: Http/lib/http/CMakeFiles/lib_src1_exe.dir/middleware/cookies.cpp.o.requires
	$(MAKE) -f Http/lib/http/CMakeFiles/lib_src1_exe.dir/build.make Http/lib/http/CMakeFiles/lib_src1_exe.dir/middleware/cookies.cpp.o.provides.build
.PHONY : Http/lib/http/CMakeFiles/lib_src1_exe.dir/middleware/cookies.cpp.o.provides

Http/lib/http/CMakeFiles/lib_src1_exe.dir/middleware/cookies.cpp.o.provides.build: Http/lib/http/CMakeFiles/lib_src1_exe.dir/middleware/cookies.cpp.o


Http/lib/http/CMakeFiles/lib_src1_exe.dir/middleware/session.cpp.o: Http/lib/http/CMakeFiles/lib_src1_exe.dir/flags.make
Http/lib/http/CMakeFiles/lib_src1_exe.dir/middleware/session.cpp.o: ../Http/lib/http/middleware/session.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Interview-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Http/lib/http/CMakeFiles/lib_src1_exe.dir/middleware/session.cpp.o"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http/lib/http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lib_src1_exe.dir/middleware/session.cpp.o -c /Users/ning/Interview-cpp/Http/lib/http/middleware/session.cpp

Http/lib/http/CMakeFiles/lib_src1_exe.dir/middleware/session.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib_src1_exe.dir/middleware/session.cpp.i"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http/lib/http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Interview-cpp/Http/lib/http/middleware/session.cpp > CMakeFiles/lib_src1_exe.dir/middleware/session.cpp.i

Http/lib/http/CMakeFiles/lib_src1_exe.dir/middleware/session.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib_src1_exe.dir/middleware/session.cpp.s"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http/lib/http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Interview-cpp/Http/lib/http/middleware/session.cpp -o CMakeFiles/lib_src1_exe.dir/middleware/session.cpp.s

Http/lib/http/CMakeFiles/lib_src1_exe.dir/middleware/session.cpp.o.requires:

.PHONY : Http/lib/http/CMakeFiles/lib_src1_exe.dir/middleware/session.cpp.o.requires

Http/lib/http/CMakeFiles/lib_src1_exe.dir/middleware/session.cpp.o.provides: Http/lib/http/CMakeFiles/lib_src1_exe.dir/middleware/session.cpp.o.requires
	$(MAKE) -f Http/lib/http/CMakeFiles/lib_src1_exe.dir/build.make Http/lib/http/CMakeFiles/lib_src1_exe.dir/middleware/session.cpp.o.provides.build
.PHONY : Http/lib/http/CMakeFiles/lib_src1_exe.dir/middleware/session.cpp.o.provides

Http/lib/http/CMakeFiles/lib_src1_exe.dir/middleware/session.cpp.o.provides.build: Http/lib/http/CMakeFiles/lib_src1_exe.dir/middleware/session.cpp.o


Http/lib/http/CMakeFiles/lib_src1_exe.dir/aop.cpp.o: Http/lib/http/CMakeFiles/lib_src1_exe.dir/flags.make
Http/lib/http/CMakeFiles/lib_src1_exe.dir/aop.cpp.o: ../Http/lib/http/aop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Interview-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object Http/lib/http/CMakeFiles/lib_src1_exe.dir/aop.cpp.o"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http/lib/http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lib_src1_exe.dir/aop.cpp.o -c /Users/ning/Interview-cpp/Http/lib/http/aop.cpp

Http/lib/http/CMakeFiles/lib_src1_exe.dir/aop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib_src1_exe.dir/aop.cpp.i"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http/lib/http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Interview-cpp/Http/lib/http/aop.cpp > CMakeFiles/lib_src1_exe.dir/aop.cpp.i

Http/lib/http/CMakeFiles/lib_src1_exe.dir/aop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib_src1_exe.dir/aop.cpp.s"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http/lib/http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Interview-cpp/Http/lib/http/aop.cpp -o CMakeFiles/lib_src1_exe.dir/aop.cpp.s

Http/lib/http/CMakeFiles/lib_src1_exe.dir/aop.cpp.o.requires:

.PHONY : Http/lib/http/CMakeFiles/lib_src1_exe.dir/aop.cpp.o.requires

Http/lib/http/CMakeFiles/lib_src1_exe.dir/aop.cpp.o.provides: Http/lib/http/CMakeFiles/lib_src1_exe.dir/aop.cpp.o.requires
	$(MAKE) -f Http/lib/http/CMakeFiles/lib_src1_exe.dir/build.make Http/lib/http/CMakeFiles/lib_src1_exe.dir/aop.cpp.o.provides.build
.PHONY : Http/lib/http/CMakeFiles/lib_src1_exe.dir/aop.cpp.o.provides

Http/lib/http/CMakeFiles/lib_src1_exe.dir/aop.cpp.o.provides.build: Http/lib/http/CMakeFiles/lib_src1_exe.dir/aop.cpp.o


Http/lib/http/CMakeFiles/lib_src1_exe.dir/context_container.cpp.o: Http/lib/http/CMakeFiles/lib_src1_exe.dir/flags.make
Http/lib/http/CMakeFiles/lib_src1_exe.dir/context_container.cpp.o: ../Http/lib/http/context_container.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Interview-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object Http/lib/http/CMakeFiles/lib_src1_exe.dir/context_container.cpp.o"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http/lib/http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lib_src1_exe.dir/context_container.cpp.o -c /Users/ning/Interview-cpp/Http/lib/http/context_container.cpp

Http/lib/http/CMakeFiles/lib_src1_exe.dir/context_container.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib_src1_exe.dir/context_container.cpp.i"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http/lib/http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Interview-cpp/Http/lib/http/context_container.cpp > CMakeFiles/lib_src1_exe.dir/context_container.cpp.i

Http/lib/http/CMakeFiles/lib_src1_exe.dir/context_container.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib_src1_exe.dir/context_container.cpp.s"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http/lib/http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Interview-cpp/Http/lib/http/context_container.cpp -o CMakeFiles/lib_src1_exe.dir/context_container.cpp.s

Http/lib/http/CMakeFiles/lib_src1_exe.dir/context_container.cpp.o.requires:

.PHONY : Http/lib/http/CMakeFiles/lib_src1_exe.dir/context_container.cpp.o.requires

Http/lib/http/CMakeFiles/lib_src1_exe.dir/context_container.cpp.o.provides: Http/lib/http/CMakeFiles/lib_src1_exe.dir/context_container.cpp.o.requires
	$(MAKE) -f Http/lib/http/CMakeFiles/lib_src1_exe.dir/build.make Http/lib/http/CMakeFiles/lib_src1_exe.dir/context_container.cpp.o.provides.build
.PHONY : Http/lib/http/CMakeFiles/lib_src1_exe.dir/context_container.cpp.o.provides

Http/lib/http/CMakeFiles/lib_src1_exe.dir/context_container.cpp.o.provides.build: Http/lib/http/CMakeFiles/lib_src1_exe.dir/context_container.cpp.o


Http/lib/http/CMakeFiles/lib_src1_exe.dir/function_traits.cpp.o: Http/lib/http/CMakeFiles/lib_src1_exe.dir/flags.make
Http/lib/http/CMakeFiles/lib_src1_exe.dir/function_traits.cpp.o: ../Http/lib/http/function_traits.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Interview-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object Http/lib/http/CMakeFiles/lib_src1_exe.dir/function_traits.cpp.o"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http/lib/http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lib_src1_exe.dir/function_traits.cpp.o -c /Users/ning/Interview-cpp/Http/lib/http/function_traits.cpp

Http/lib/http/CMakeFiles/lib_src1_exe.dir/function_traits.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib_src1_exe.dir/function_traits.cpp.i"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http/lib/http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Interview-cpp/Http/lib/http/function_traits.cpp > CMakeFiles/lib_src1_exe.dir/function_traits.cpp.i

Http/lib/http/CMakeFiles/lib_src1_exe.dir/function_traits.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib_src1_exe.dir/function_traits.cpp.s"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http/lib/http && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Interview-cpp/Http/lib/http/function_traits.cpp -o CMakeFiles/lib_src1_exe.dir/function_traits.cpp.s

Http/lib/http/CMakeFiles/lib_src1_exe.dir/function_traits.cpp.o.requires:

.PHONY : Http/lib/http/CMakeFiles/lib_src1_exe.dir/function_traits.cpp.o.requires

Http/lib/http/CMakeFiles/lib_src1_exe.dir/function_traits.cpp.o.provides: Http/lib/http/CMakeFiles/lib_src1_exe.dir/function_traits.cpp.o.requires
	$(MAKE) -f Http/lib/http/CMakeFiles/lib_src1_exe.dir/build.make Http/lib/http/CMakeFiles/lib_src1_exe.dir/function_traits.cpp.o.provides.build
.PHONY : Http/lib/http/CMakeFiles/lib_src1_exe.dir/function_traits.cpp.o.provides

Http/lib/http/CMakeFiles/lib_src1_exe.dir/function_traits.cpp.o.provides.build: Http/lib/http/CMakeFiles/lib_src1_exe.dir/function_traits.cpp.o


# Object files for target lib_src1_exe
lib_src1_exe_OBJECTS = \
"CMakeFiles/lib_src1_exe.dir/middleware/cookies.cpp.o" \
"CMakeFiles/lib_src1_exe.dir/middleware/session.cpp.o" \
"CMakeFiles/lib_src1_exe.dir/aop.cpp.o" \
"CMakeFiles/lib_src1_exe.dir/context_container.cpp.o" \
"CMakeFiles/lib_src1_exe.dir/function_traits.cpp.o"

# External object files for target lib_src1_exe
lib_src1_exe_EXTERNAL_OBJECTS =

Http/lib/http/lib_src1_exe: Http/lib/http/CMakeFiles/lib_src1_exe.dir/middleware/cookies.cpp.o
Http/lib/http/lib_src1_exe: Http/lib/http/CMakeFiles/lib_src1_exe.dir/middleware/session.cpp.o
Http/lib/http/lib_src1_exe: Http/lib/http/CMakeFiles/lib_src1_exe.dir/aop.cpp.o
Http/lib/http/lib_src1_exe: Http/lib/http/CMakeFiles/lib_src1_exe.dir/context_container.cpp.o
Http/lib/http/lib_src1_exe: Http/lib/http/CMakeFiles/lib_src1_exe.dir/function_traits.cpp.o
Http/lib/http/lib_src1_exe: Http/lib/http/CMakeFiles/lib_src1_exe.dir/build.make
Http/lib/http/lib_src1_exe: Http/lib/http/CMakeFiles/lib_src1_exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ning/Interview-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable lib_src1_exe"
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http/lib/http && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lib_src1_exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Http/lib/http/CMakeFiles/lib_src1_exe.dir/build: Http/lib/http/lib_src1_exe

.PHONY : Http/lib/http/CMakeFiles/lib_src1_exe.dir/build

Http/lib/http/CMakeFiles/lib_src1_exe.dir/requires: Http/lib/http/CMakeFiles/lib_src1_exe.dir/middleware/cookies.cpp.o.requires
Http/lib/http/CMakeFiles/lib_src1_exe.dir/requires: Http/lib/http/CMakeFiles/lib_src1_exe.dir/middleware/session.cpp.o.requires
Http/lib/http/CMakeFiles/lib_src1_exe.dir/requires: Http/lib/http/CMakeFiles/lib_src1_exe.dir/aop.cpp.o.requires
Http/lib/http/CMakeFiles/lib_src1_exe.dir/requires: Http/lib/http/CMakeFiles/lib_src1_exe.dir/context_container.cpp.o.requires
Http/lib/http/CMakeFiles/lib_src1_exe.dir/requires: Http/lib/http/CMakeFiles/lib_src1_exe.dir/function_traits.cpp.o.requires

.PHONY : Http/lib/http/CMakeFiles/lib_src1_exe.dir/requires

Http/lib/http/CMakeFiles/lib_src1_exe.dir/clean:
	cd /Users/ning/Interview-cpp/cmake-build-debug/Http/lib/http && $(CMAKE_COMMAND) -P CMakeFiles/lib_src1_exe.dir/cmake_clean.cmake
.PHONY : Http/lib/http/CMakeFiles/lib_src1_exe.dir/clean

Http/lib/http/CMakeFiles/lib_src1_exe.dir/depend:
	cd /Users/ning/Interview-cpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ning/Interview-cpp /Users/ning/Interview-cpp/Http/lib/http /Users/ning/Interview-cpp/cmake-build-debug /Users/ning/Interview-cpp/cmake-build-debug/Http/lib/http /Users/ning/Interview-cpp/cmake-build-debug/Http/lib/http/CMakeFiles/lib_src1_exe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Http/lib/http/CMakeFiles/lib_src1_exe.dir/depend
