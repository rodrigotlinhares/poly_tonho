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
CMAKE_SOURCE_DIR = /home/rodrigolinhares/Desktop/poly_tonho/videoPolynom_wx_tracking

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rodrigolinhares/Desktop/poly_tonho/videoPolynom_wx_tracking/build

# Include any dependencies generated for this target.
include src/dip/CMakeFiles/DiffGray.dir/depend.make

# Include the progress variables for this target.
include src/dip/CMakeFiles/DiffGray.dir/progress.make

# Include the compile flags for this target's objects.
include src/dip/CMakeFiles/DiffGray.dir/flags.make

src/dip/CMakeFiles/DiffGray.dir/diffGray.cpp.o: src/dip/CMakeFiles/DiffGray.dir/flags.make
src/dip/CMakeFiles/DiffGray.dir/diffGray.cpp.o: ../src/dip/diffGray.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/rodrigolinhares/Desktop/poly_tonho/videoPolynom_wx_tracking/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/dip/CMakeFiles/DiffGray.dir/diffGray.cpp.o"
	cd /home/rodrigolinhares/Desktop/poly_tonho/videoPolynom_wx_tracking/build/src/dip && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DiffGray.dir/diffGray.cpp.o -c /home/rodrigolinhares/Desktop/poly_tonho/videoPolynom_wx_tracking/src/dip/diffGray.cpp

src/dip/CMakeFiles/DiffGray.dir/diffGray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DiffGray.dir/diffGray.cpp.i"
	cd /home/rodrigolinhares/Desktop/poly_tonho/videoPolynom_wx_tracking/build/src/dip && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/rodrigolinhares/Desktop/poly_tonho/videoPolynom_wx_tracking/src/dip/diffGray.cpp > CMakeFiles/DiffGray.dir/diffGray.cpp.i

src/dip/CMakeFiles/DiffGray.dir/diffGray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DiffGray.dir/diffGray.cpp.s"
	cd /home/rodrigolinhares/Desktop/poly_tonho/videoPolynom_wx_tracking/build/src/dip && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/rodrigolinhares/Desktop/poly_tonho/videoPolynom_wx_tracking/src/dip/diffGray.cpp -o CMakeFiles/DiffGray.dir/diffGray.cpp.s

src/dip/CMakeFiles/DiffGray.dir/diffGray.cpp.o.requires:
.PHONY : src/dip/CMakeFiles/DiffGray.dir/diffGray.cpp.o.requires

src/dip/CMakeFiles/DiffGray.dir/diffGray.cpp.o.provides: src/dip/CMakeFiles/DiffGray.dir/diffGray.cpp.o.requires
	$(MAKE) -f src/dip/CMakeFiles/DiffGray.dir/build.make src/dip/CMakeFiles/DiffGray.dir/diffGray.cpp.o.provides.build
.PHONY : src/dip/CMakeFiles/DiffGray.dir/diffGray.cpp.o.provides

src/dip/CMakeFiles/DiffGray.dir/diffGray.cpp.o.provides.build: src/dip/CMakeFiles/DiffGray.dir/diffGray.cpp.o

# Object files for target DiffGray
DiffGray_OBJECTS = \
"CMakeFiles/DiffGray.dir/diffGray.cpp.o"

# External object files for target DiffGray
DiffGray_EXTERNAL_OBJECTS =

src/dip/libDiffGray.a: src/dip/CMakeFiles/DiffGray.dir/diffGray.cpp.o
src/dip/libDiffGray.a: src/dip/CMakeFiles/DiffGray.dir/build.make
src/dip/libDiffGray.a: src/dip/CMakeFiles/DiffGray.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libDiffGray.a"
	cd /home/rodrigolinhares/Desktop/poly_tonho/videoPolynom_wx_tracking/build/src/dip && $(CMAKE_COMMAND) -P CMakeFiles/DiffGray.dir/cmake_clean_target.cmake
	cd /home/rodrigolinhares/Desktop/poly_tonho/videoPolynom_wx_tracking/build/src/dip && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DiffGray.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/dip/CMakeFiles/DiffGray.dir/build: src/dip/libDiffGray.a
.PHONY : src/dip/CMakeFiles/DiffGray.dir/build

src/dip/CMakeFiles/DiffGray.dir/requires: src/dip/CMakeFiles/DiffGray.dir/diffGray.cpp.o.requires
.PHONY : src/dip/CMakeFiles/DiffGray.dir/requires

src/dip/CMakeFiles/DiffGray.dir/clean:
	cd /home/rodrigolinhares/Desktop/poly_tonho/videoPolynom_wx_tracking/build/src/dip && $(CMAKE_COMMAND) -P CMakeFiles/DiffGray.dir/cmake_clean.cmake
.PHONY : src/dip/CMakeFiles/DiffGray.dir/clean

src/dip/CMakeFiles/DiffGray.dir/depend:
	cd /home/rodrigolinhares/Desktop/poly_tonho/videoPolynom_wx_tracking/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rodrigolinhares/Desktop/poly_tonho/videoPolynom_wx_tracking /home/rodrigolinhares/Desktop/poly_tonho/videoPolynom_wx_tracking/src/dip /home/rodrigolinhares/Desktop/poly_tonho/videoPolynom_wx_tracking/build /home/rodrigolinhares/Desktop/poly_tonho/videoPolynom_wx_tracking/build/src/dip /home/rodrigolinhares/Desktop/poly_tonho/videoPolynom_wx_tracking/build/src/dip/CMakeFiles/DiffGray.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/dip/CMakeFiles/DiffGray.dir/depend

