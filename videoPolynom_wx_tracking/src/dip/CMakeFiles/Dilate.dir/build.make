# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lapix/Desktop/hmm/videoPolynom_wx_tracking

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lapix/Desktop/hmm/videoPolynom_wx_tracking

# Include any dependencies generated for this target.
include src/dip/CMakeFiles/Dilate.dir/depend.make

# Include the progress variables for this target.
include src/dip/CMakeFiles/Dilate.dir/progress.make

# Include the compile flags for this target's objects.
include src/dip/CMakeFiles/Dilate.dir/flags.make

src/dip/CMakeFiles/Dilate.dir/dilate.cpp.o: src/dip/CMakeFiles/Dilate.dir/flags.make
src/dip/CMakeFiles/Dilate.dir/dilate.cpp.o: src/dip/dilate.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/dip/CMakeFiles/Dilate.dir/dilate.cpp.o"
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/dip && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Dilate.dir/dilate.cpp.o -c /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/dip/dilate.cpp

src/dip/CMakeFiles/Dilate.dir/dilate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Dilate.dir/dilate.cpp.i"
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/dip && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/dip/dilate.cpp > CMakeFiles/Dilate.dir/dilate.cpp.i

src/dip/CMakeFiles/Dilate.dir/dilate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Dilate.dir/dilate.cpp.s"
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/dip && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/dip/dilate.cpp -o CMakeFiles/Dilate.dir/dilate.cpp.s

src/dip/CMakeFiles/Dilate.dir/dilate.cpp.o.requires:
.PHONY : src/dip/CMakeFiles/Dilate.dir/dilate.cpp.o.requires

src/dip/CMakeFiles/Dilate.dir/dilate.cpp.o.provides: src/dip/CMakeFiles/Dilate.dir/dilate.cpp.o.requires
	$(MAKE) -f src/dip/CMakeFiles/Dilate.dir/build.make src/dip/CMakeFiles/Dilate.dir/dilate.cpp.o.provides.build
.PHONY : src/dip/CMakeFiles/Dilate.dir/dilate.cpp.o.provides

src/dip/CMakeFiles/Dilate.dir/dilate.cpp.o.provides.build: src/dip/CMakeFiles/Dilate.dir/dilate.cpp.o

# Object files for target Dilate
Dilate_OBJECTS = \
"CMakeFiles/Dilate.dir/dilate.cpp.o"

# External object files for target Dilate
Dilate_EXTERNAL_OBJECTS =

src/dip/libDilate.a: src/dip/CMakeFiles/Dilate.dir/dilate.cpp.o
src/dip/libDilate.a: src/dip/CMakeFiles/Dilate.dir/build.make
src/dip/libDilate.a: src/dip/CMakeFiles/Dilate.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libDilate.a"
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/dip && $(CMAKE_COMMAND) -P CMakeFiles/Dilate.dir/cmake_clean_target.cmake
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/dip && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Dilate.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/dip/CMakeFiles/Dilate.dir/build: src/dip/libDilate.a
.PHONY : src/dip/CMakeFiles/Dilate.dir/build

src/dip/CMakeFiles/Dilate.dir/requires: src/dip/CMakeFiles/Dilate.dir/dilate.cpp.o.requires
.PHONY : src/dip/CMakeFiles/Dilate.dir/requires

src/dip/CMakeFiles/Dilate.dir/clean:
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/dip && $(CMAKE_COMMAND) -P CMakeFiles/Dilate.dir/cmake_clean.cmake
.PHONY : src/dip/CMakeFiles/Dilate.dir/clean

src/dip/CMakeFiles/Dilate.dir/depend:
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lapix/Desktop/hmm/videoPolynom_wx_tracking /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/dip /home/lapix/Desktop/hmm/videoPolynom_wx_tracking /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/dip /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/dip/CMakeFiles/Dilate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/dip/CMakeFiles/Dilate.dir/depend

