# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /cygdrive/c/Users/minhh/.CLion2019.2/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/minhh/.CLion2019.2/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/minhh/CLionProjects/CMPE-126-Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/minhh/CLionProjects/CMPE-126-Project/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CMPE-126.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CMPE-126.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CMPE-126.dir/flags.make

CMakeFiles/CMPE-126.dir/main.cpp.o: CMakeFiles/CMPE-126.dir/flags.make
CMakeFiles/CMPE-126.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/minhh/CLionProjects/CMPE-126-Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CMPE-126.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CMPE-126.dir/main.cpp.o -c /cygdrive/c/Users/minhh/CLionProjects/CMPE-126-Project/main.cpp

CMakeFiles/CMPE-126.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CMPE-126.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/minhh/CLionProjects/CMPE-126-Project/main.cpp > CMakeFiles/CMPE-126.dir/main.cpp.i

CMakeFiles/CMPE-126.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CMPE-126.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/minhh/CLionProjects/CMPE-126-Project/main.cpp -o CMakeFiles/CMPE-126.dir/main.cpp.s

CMakeFiles/CMPE-126.dir/school.cpp.o: CMakeFiles/CMPE-126.dir/flags.make
CMakeFiles/CMPE-126.dir/school.cpp.o: ../school.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/minhh/CLionProjects/CMPE-126-Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CMPE-126.dir/school.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CMPE-126.dir/school.cpp.o -c /cygdrive/c/Users/minhh/CLionProjects/CMPE-126-Project/school.cpp

CMakeFiles/CMPE-126.dir/school.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CMPE-126.dir/school.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/minhh/CLionProjects/CMPE-126-Project/school.cpp > CMakeFiles/CMPE-126.dir/school.cpp.i

CMakeFiles/CMPE-126.dir/school.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CMPE-126.dir/school.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/minhh/CLionProjects/CMPE-126-Project/school.cpp -o CMakeFiles/CMPE-126.dir/school.cpp.s

# Object files for target CMPE-126
CMPE__126_OBJECTS = \
"CMakeFiles/CMPE-126.dir/main.cpp.o" \
"CMakeFiles/CMPE-126.dir/school.cpp.o"

# External object files for target CMPE-126
CMPE__126_EXTERNAL_OBJECTS =

CMPE-126.exe: CMakeFiles/CMPE-126.dir/main.cpp.o
CMPE-126.exe: CMakeFiles/CMPE-126.dir/school.cpp.o
CMPE-126.exe: CMakeFiles/CMPE-126.dir/build.make
CMPE-126.exe: CMakeFiles/CMPE-126.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/minhh/CLionProjects/CMPE-126-Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable CMPE-126.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CMPE-126.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CMPE-126.dir/build: CMPE-126.exe

.PHONY : CMakeFiles/CMPE-126.dir/build

CMakeFiles/CMPE-126.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CMPE-126.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CMPE-126.dir/clean

CMakeFiles/CMPE-126.dir/depend:
	cd /cygdrive/c/Users/minhh/CLionProjects/CMPE-126-Project/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/minhh/CLionProjects/CMPE-126-Project /cygdrive/c/Users/minhh/CLionProjects/CMPE-126-Project /cygdrive/c/Users/minhh/CLionProjects/CMPE-126-Project/cmake-build-debug /cygdrive/c/Users/minhh/CLionProjects/CMPE-126-Project/cmake-build-debug /cygdrive/c/Users/minhh/CLionProjects/CMPE-126-Project/cmake-build-debug/CMakeFiles/CMPE-126.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CMPE-126.dir/depend

