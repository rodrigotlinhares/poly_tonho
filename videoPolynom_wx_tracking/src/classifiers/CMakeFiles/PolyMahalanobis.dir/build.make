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
include src/classifiers/CMakeFiles/PolyMahalanobis.dir/depend.make

# Include the progress variables for this target.
include src/classifiers/CMakeFiles/PolyMahalanobis.dir/progress.make

# Include the compile flags for this target's objects.
include src/classifiers/CMakeFiles/PolyMahalanobis.dir/flags.make

src/classifiers/CMakeFiles/PolyMahalanobis.dir/polyMahalanobis.cpp.o: src/classifiers/CMakeFiles/PolyMahalanobis.dir/flags.make
src/classifiers/CMakeFiles/PolyMahalanobis.dir/polyMahalanobis.cpp.o: src/classifiers/polyMahalanobis.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/classifiers/CMakeFiles/PolyMahalanobis.dir/polyMahalanobis.cpp.o"
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/classifiers && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/PolyMahalanobis.dir/polyMahalanobis.cpp.o -c /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/classifiers/polyMahalanobis.cpp

src/classifiers/CMakeFiles/PolyMahalanobis.dir/polyMahalanobis.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PolyMahalanobis.dir/polyMahalanobis.cpp.i"
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/classifiers && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/classifiers/polyMahalanobis.cpp > CMakeFiles/PolyMahalanobis.dir/polyMahalanobis.cpp.i

src/classifiers/CMakeFiles/PolyMahalanobis.dir/polyMahalanobis.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PolyMahalanobis.dir/polyMahalanobis.cpp.s"
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/classifiers && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/classifiers/polyMahalanobis.cpp -o CMakeFiles/PolyMahalanobis.dir/polyMahalanobis.cpp.s

src/classifiers/CMakeFiles/PolyMahalanobis.dir/polyMahalanobis.cpp.o.requires:
.PHONY : src/classifiers/CMakeFiles/PolyMahalanobis.dir/polyMahalanobis.cpp.o.requires

src/classifiers/CMakeFiles/PolyMahalanobis.dir/polyMahalanobis.cpp.o.provides: src/classifiers/CMakeFiles/PolyMahalanobis.dir/polyMahalanobis.cpp.o.requires
	$(MAKE) -f src/classifiers/CMakeFiles/PolyMahalanobis.dir/build.make src/classifiers/CMakeFiles/PolyMahalanobis.dir/polyMahalanobis.cpp.o.provides.build
.PHONY : src/classifiers/CMakeFiles/PolyMahalanobis.dir/polyMahalanobis.cpp.o.provides

src/classifiers/CMakeFiles/PolyMahalanobis.dir/polyMahalanobis.cpp.o.provides.build: src/classifiers/CMakeFiles/PolyMahalanobis.dir/polyMahalanobis.cpp.o

# Object files for target PolyMahalanobis
PolyMahalanobis_OBJECTS = \
"CMakeFiles/PolyMahalanobis.dir/polyMahalanobis.cpp.o"

# External object files for target PolyMahalanobis
PolyMahalanobis_EXTERNAL_OBJECTS =

src/classifiers/libPolyMahalanobis.a: src/classifiers/CMakeFiles/PolyMahalanobis.dir/polyMahalanobis.cpp.o
src/classifiers/libPolyMahalanobis.a: src/classifiers/CMakeFiles/PolyMahalanobis.dir/build.make
src/classifiers/libPolyMahalanobis.a: src/classifiers/CMakeFiles/PolyMahalanobis.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libPolyMahalanobis.a"
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/classifiers && $(CMAKE_COMMAND) -P CMakeFiles/PolyMahalanobis.dir/cmake_clean_target.cmake
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/classifiers && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PolyMahalanobis.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/classifiers/CMakeFiles/PolyMahalanobis.dir/build: src/classifiers/libPolyMahalanobis.a
.PHONY : src/classifiers/CMakeFiles/PolyMahalanobis.dir/build

src/classifiers/CMakeFiles/PolyMahalanobis.dir/requires: src/classifiers/CMakeFiles/PolyMahalanobis.dir/polyMahalanobis.cpp.o.requires
.PHONY : src/classifiers/CMakeFiles/PolyMahalanobis.dir/requires

src/classifiers/CMakeFiles/PolyMahalanobis.dir/clean:
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/classifiers && $(CMAKE_COMMAND) -P CMakeFiles/PolyMahalanobis.dir/cmake_clean.cmake
.PHONY : src/classifiers/CMakeFiles/PolyMahalanobis.dir/clean

src/classifiers/CMakeFiles/PolyMahalanobis.dir/depend:
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lapix/Desktop/hmm/videoPolynom_wx_tracking /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/classifiers /home/lapix/Desktop/hmm/videoPolynom_wx_tracking /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/classifiers /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/classifiers/CMakeFiles/PolyMahalanobis.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/classifiers/CMakeFiles/PolyMahalanobis.dir/depend

