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
include src/camModule/CMakeFiles/CamModule.dir/depend.make

# Include the progress variables for this target.
include src/camModule/CMakeFiles/CamModule.dir/progress.make

# Include the compile flags for this target's objects.
include src/camModule/CMakeFiles/CamModule.dir/flags.make

src/camModule/CMakeFiles/CamModule.dir/camModule.cpp.o: src/camModule/CMakeFiles/CamModule.dir/flags.make
src/camModule/CMakeFiles/CamModule.dir/camModule.cpp.o: src/camModule/camModule.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/camModule/CMakeFiles/CamModule.dir/camModule.cpp.o"
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/camModule && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/CamModule.dir/camModule.cpp.o -c /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/camModule/camModule.cpp

src/camModule/CMakeFiles/CamModule.dir/camModule.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CamModule.dir/camModule.cpp.i"
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/camModule && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/camModule/camModule.cpp > CMakeFiles/CamModule.dir/camModule.cpp.i

src/camModule/CMakeFiles/CamModule.dir/camModule.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CamModule.dir/camModule.cpp.s"
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/camModule && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/camModule/camModule.cpp -o CMakeFiles/CamModule.dir/camModule.cpp.s

src/camModule/CMakeFiles/CamModule.dir/camModule.cpp.o.requires:
.PHONY : src/camModule/CMakeFiles/CamModule.dir/camModule.cpp.o.requires

src/camModule/CMakeFiles/CamModule.dir/camModule.cpp.o.provides: src/camModule/CMakeFiles/CamModule.dir/camModule.cpp.o.requires
	$(MAKE) -f src/camModule/CMakeFiles/CamModule.dir/build.make src/camModule/CMakeFiles/CamModule.dir/camModule.cpp.o.provides.build
.PHONY : src/camModule/CMakeFiles/CamModule.dir/camModule.cpp.o.provides

src/camModule/CMakeFiles/CamModule.dir/camModule.cpp.o.provides.build: src/camModule/CMakeFiles/CamModule.dir/camModule.cpp.o

# Object files for target CamModule
CamModule_OBJECTS = \
"CMakeFiles/CamModule.dir/camModule.cpp.o"

# External object files for target CamModule
CamModule_EXTERNAL_OBJECTS =

src/camModule/libCamModule.a: src/camModule/CMakeFiles/CamModule.dir/camModule.cpp.o
src/camModule/libCamModule.a: src/camModule/CMakeFiles/CamModule.dir/build.make
src/camModule/libCamModule.a: src/camModule/CMakeFiles/CamModule.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libCamModule.a"
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/camModule && $(CMAKE_COMMAND) -P CMakeFiles/CamModule.dir/cmake_clean_target.cmake
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/camModule && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CamModule.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/camModule/CMakeFiles/CamModule.dir/build: src/camModule/libCamModule.a
.PHONY : src/camModule/CMakeFiles/CamModule.dir/build

src/camModule/CMakeFiles/CamModule.dir/requires: src/camModule/CMakeFiles/CamModule.dir/camModule.cpp.o.requires
.PHONY : src/camModule/CMakeFiles/CamModule.dir/requires

src/camModule/CMakeFiles/CamModule.dir/clean:
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/camModule && $(CMAKE_COMMAND) -P CMakeFiles/CamModule.dir/cmake_clean.cmake
.PHONY : src/camModule/CMakeFiles/CamModule.dir/clean

src/camModule/CMakeFiles/CamModule.dir/depend:
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lapix/Desktop/hmm/videoPolynom_wx_tracking /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/camModule /home/lapix/Desktop/hmm/videoPolynom_wx_tracking /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/camModule /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/camModule/CMakeFiles/CamModule.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/camModule/CMakeFiles/CamModule.dir/depend

