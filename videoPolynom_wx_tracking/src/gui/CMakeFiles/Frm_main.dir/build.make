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
include src/gui/CMakeFiles/Frm_main.dir/depend.make

# Include the progress variables for this target.
include src/gui/CMakeFiles/Frm_main.dir/progress.make

# Include the compile flags for this target's objects.
include src/gui/CMakeFiles/Frm_main.dir/flags.make

src/gui/CMakeFiles/Frm_main.dir/frm_main.cpp.o: src/gui/CMakeFiles/Frm_main.dir/flags.make
src/gui/CMakeFiles/Frm_main.dir/frm_main.cpp.o: src/gui/frm_main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/gui/CMakeFiles/Frm_main.dir/frm_main.cpp.o"
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/gui && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Frm_main.dir/frm_main.cpp.o -c /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/gui/frm_main.cpp

src/gui/CMakeFiles/Frm_main.dir/frm_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Frm_main.dir/frm_main.cpp.i"
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/gui && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/gui/frm_main.cpp > CMakeFiles/Frm_main.dir/frm_main.cpp.i

src/gui/CMakeFiles/Frm_main.dir/frm_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Frm_main.dir/frm_main.cpp.s"
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/gui && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/gui/frm_main.cpp -o CMakeFiles/Frm_main.dir/frm_main.cpp.s

src/gui/CMakeFiles/Frm_main.dir/frm_main.cpp.o.requires:
.PHONY : src/gui/CMakeFiles/Frm_main.dir/frm_main.cpp.o.requires

src/gui/CMakeFiles/Frm_main.dir/frm_main.cpp.o.provides: src/gui/CMakeFiles/Frm_main.dir/frm_main.cpp.o.requires
	$(MAKE) -f src/gui/CMakeFiles/Frm_main.dir/build.make src/gui/CMakeFiles/Frm_main.dir/frm_main.cpp.o.provides.build
.PHONY : src/gui/CMakeFiles/Frm_main.dir/frm_main.cpp.o.provides

src/gui/CMakeFiles/Frm_main.dir/frm_main.cpp.o.provides.build: src/gui/CMakeFiles/Frm_main.dir/frm_main.cpp.o

# Object files for target Frm_main
Frm_main_OBJECTS = \
"CMakeFiles/Frm_main.dir/frm_main.cpp.o"

# External object files for target Frm_main
Frm_main_EXTERNAL_OBJECTS =

src/gui/libFrm_main.a: src/gui/CMakeFiles/Frm_main.dir/frm_main.cpp.o
src/gui/libFrm_main.a: src/gui/CMakeFiles/Frm_main.dir/build.make
src/gui/libFrm_main.a: src/gui/CMakeFiles/Frm_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libFrm_main.a"
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/gui && $(CMAKE_COMMAND) -P CMakeFiles/Frm_main.dir/cmake_clean_target.cmake
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/gui && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Frm_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/gui/CMakeFiles/Frm_main.dir/build: src/gui/libFrm_main.a
.PHONY : src/gui/CMakeFiles/Frm_main.dir/build

src/gui/CMakeFiles/Frm_main.dir/requires: src/gui/CMakeFiles/Frm_main.dir/frm_main.cpp.o.requires
.PHONY : src/gui/CMakeFiles/Frm_main.dir/requires

src/gui/CMakeFiles/Frm_main.dir/clean:
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/gui && $(CMAKE_COMMAND) -P CMakeFiles/Frm_main.dir/cmake_clean.cmake
.PHONY : src/gui/CMakeFiles/Frm_main.dir/clean

src/gui/CMakeFiles/Frm_main.dir/depend:
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lapix/Desktop/hmm/videoPolynom_wx_tracking /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/gui /home/lapix/Desktop/hmm/videoPolynom_wx_tracking /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/gui /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/gui/CMakeFiles/Frm_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/gui/CMakeFiles/Frm_main.dir/depend

