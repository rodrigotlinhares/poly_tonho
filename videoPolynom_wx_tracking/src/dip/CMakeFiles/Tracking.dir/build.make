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
include src/dip/CMakeFiles/Tracking.dir/depend.make

# Include the progress variables for this target.
include src/dip/CMakeFiles/Tracking.dir/progress.make

# Include the compile flags for this target's objects.
include src/dip/CMakeFiles/Tracking.dir/flags.make

src/dip/CMakeFiles/Tracking.dir/tracking.cpp.o: src/dip/CMakeFiles/Tracking.dir/flags.make
src/dip/CMakeFiles/Tracking.dir/tracking.cpp.o: src/dip/tracking.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/dip/CMakeFiles/Tracking.dir/tracking.cpp.o"
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/dip && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Tracking.dir/tracking.cpp.o -c /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/dip/tracking.cpp

src/dip/CMakeFiles/Tracking.dir/tracking.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tracking.dir/tracking.cpp.i"
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/dip && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/dip/tracking.cpp > CMakeFiles/Tracking.dir/tracking.cpp.i

src/dip/CMakeFiles/Tracking.dir/tracking.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tracking.dir/tracking.cpp.s"
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/dip && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/dip/tracking.cpp -o CMakeFiles/Tracking.dir/tracking.cpp.s

src/dip/CMakeFiles/Tracking.dir/tracking.cpp.o.requires:
.PHONY : src/dip/CMakeFiles/Tracking.dir/tracking.cpp.o.requires

src/dip/CMakeFiles/Tracking.dir/tracking.cpp.o.provides: src/dip/CMakeFiles/Tracking.dir/tracking.cpp.o.requires
	$(MAKE) -f src/dip/CMakeFiles/Tracking.dir/build.make src/dip/CMakeFiles/Tracking.dir/tracking.cpp.o.provides.build
.PHONY : src/dip/CMakeFiles/Tracking.dir/tracking.cpp.o.provides

src/dip/CMakeFiles/Tracking.dir/tracking.cpp.o.provides.build: src/dip/CMakeFiles/Tracking.dir/tracking.cpp.o

# Object files for target Tracking
Tracking_OBJECTS = \
"CMakeFiles/Tracking.dir/tracking.cpp.o"

# External object files for target Tracking
Tracking_EXTERNAL_OBJECTS =

src/dip/libTracking.a: src/dip/CMakeFiles/Tracking.dir/tracking.cpp.o
src/dip/libTracking.a: src/dip/CMakeFiles/Tracking.dir/build.make
src/dip/libTracking.a: src/dip/CMakeFiles/Tracking.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libTracking.a"
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/dip && $(CMAKE_COMMAND) -P CMakeFiles/Tracking.dir/cmake_clean_target.cmake
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/dip && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Tracking.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/dip/CMakeFiles/Tracking.dir/build: src/dip/libTracking.a
.PHONY : src/dip/CMakeFiles/Tracking.dir/build

src/dip/CMakeFiles/Tracking.dir/requires: src/dip/CMakeFiles/Tracking.dir/tracking.cpp.o.requires
.PHONY : src/dip/CMakeFiles/Tracking.dir/requires

src/dip/CMakeFiles/Tracking.dir/clean:
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/dip && $(CMAKE_COMMAND) -P CMakeFiles/Tracking.dir/cmake_clean.cmake
.PHONY : src/dip/CMakeFiles/Tracking.dir/clean

src/dip/CMakeFiles/Tracking.dir/depend:
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lapix/Desktop/hmm/videoPolynom_wx_tracking /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/dip /home/lapix/Desktop/hmm/videoPolynom_wx_tracking /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/dip /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/dip/CMakeFiles/Tracking.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/dip/CMakeFiles/Tracking.dir/depend

