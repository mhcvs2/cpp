# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_SOURCE_DIR = /Users/yons/github/cpp/set

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/yons/github/cpp/set/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/set.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/set.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/set.dir/flags.make

CMakeFiles/set.dir/main.cpp.o: CMakeFiles/set.dir/flags.make
CMakeFiles/set.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yons/github/cpp/set/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/set.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/set.dir/main.cpp.o -c /Users/yons/github/cpp/set/main.cpp

CMakeFiles/set.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/set.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yons/github/cpp/set/main.cpp > CMakeFiles/set.dir/main.cpp.i

CMakeFiles/set.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/set.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yons/github/cpp/set/main.cpp -o CMakeFiles/set.dir/main.cpp.s

CMakeFiles/set.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/set.dir/main.cpp.o.requires

CMakeFiles/set.dir/main.cpp.o.provides: CMakeFiles/set.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/set.dir/build.make CMakeFiles/set.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/set.dir/main.cpp.o.provides

CMakeFiles/set.dir/main.cpp.o.provides.build: CMakeFiles/set.dir/main.cpp.o


CMakeFiles/set.dir/set.cpp.o: CMakeFiles/set.dir/flags.make
CMakeFiles/set.dir/set.cpp.o: ../set.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yons/github/cpp/set/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/set.dir/set.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/set.dir/set.cpp.o -c /Users/yons/github/cpp/set/set.cpp

CMakeFiles/set.dir/set.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/set.dir/set.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yons/github/cpp/set/set.cpp > CMakeFiles/set.dir/set.cpp.i

CMakeFiles/set.dir/set.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/set.dir/set.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yons/github/cpp/set/set.cpp -o CMakeFiles/set.dir/set.cpp.s

CMakeFiles/set.dir/set.cpp.o.requires:

.PHONY : CMakeFiles/set.dir/set.cpp.o.requires

CMakeFiles/set.dir/set.cpp.o.provides: CMakeFiles/set.dir/set.cpp.o.requires
	$(MAKE) -f CMakeFiles/set.dir/build.make CMakeFiles/set.dir/set.cpp.o.provides.build
.PHONY : CMakeFiles/set.dir/set.cpp.o.provides

CMakeFiles/set.dir/set.cpp.o.provides.build: CMakeFiles/set.dir/set.cpp.o


# Object files for target set
set_OBJECTS = \
"CMakeFiles/set.dir/main.cpp.o" \
"CMakeFiles/set.dir/set.cpp.o"

# External object files for target set
set_EXTERNAL_OBJECTS =

set: CMakeFiles/set.dir/main.cpp.o
set: CMakeFiles/set.dir/set.cpp.o
set: CMakeFiles/set.dir/build.make
set: CMakeFiles/set.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yons/github/cpp/set/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable set"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/set.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/set.dir/build: set

.PHONY : CMakeFiles/set.dir/build

CMakeFiles/set.dir/requires: CMakeFiles/set.dir/main.cpp.o.requires
CMakeFiles/set.dir/requires: CMakeFiles/set.dir/set.cpp.o.requires

.PHONY : CMakeFiles/set.dir/requires

CMakeFiles/set.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/set.dir/cmake_clean.cmake
.PHONY : CMakeFiles/set.dir/clean

CMakeFiles/set.dir/depend:
	cd /Users/yons/github/cpp/set/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yons/github/cpp/set /Users/yons/github/cpp/set /Users/yons/github/cpp/set/cmake-build-debug /Users/yons/github/cpp/set/cmake-build-debug /Users/yons/github/cpp/set/cmake-build-debug/CMakeFiles/set.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/set.dir/depend

