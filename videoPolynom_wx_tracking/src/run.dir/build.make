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
include src/gui/CMakeFiles/../../run.dir/depend.make

# Include the progress variables for this target.
include src/gui/CMakeFiles/../../run.dir/progress.make

# Include the compile flags for this target's objects.
include src/gui/CMakeFiles/../../run.dir/flags.make

src/gui/CMakeFiles/../../run.dir/guiapp.cpp.o: src/gui/CMakeFiles/../../run.dir/flags.make
src/gui/CMakeFiles/../../run.dir/guiapp.cpp.o: src/gui/guiapp.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/gui/CMakeFiles/../../run.dir/guiapp.cpp.o"
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/gui && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/../../run.dir/guiapp.cpp.o -c /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/gui/guiapp.cpp

src/gui/CMakeFiles/../../run.dir/guiapp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/../../run.dir/guiapp.cpp.i"
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/gui && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/gui/guiapp.cpp > CMakeFiles/../../run.dir/guiapp.cpp.i

src/gui/CMakeFiles/../../run.dir/guiapp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/../../run.dir/guiapp.cpp.s"
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/gui && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/gui/guiapp.cpp -o CMakeFiles/../../run.dir/guiapp.cpp.s

src/gui/CMakeFiles/../../run.dir/guiapp.cpp.o.requires:
.PHONY : src/gui/CMakeFiles/../../run.dir/guiapp.cpp.o.requires

src/gui/CMakeFiles/../../run.dir/guiapp.cpp.o.provides: src/gui/CMakeFiles/../../run.dir/guiapp.cpp.o.requires
	$(MAKE) -f src/gui/CMakeFiles/../../run.dir/build.make src/gui/CMakeFiles/../../run.dir/guiapp.cpp.o.provides.build
.PHONY : src/gui/CMakeFiles/../../run.dir/guiapp.cpp.o.provides

src/gui/CMakeFiles/../../run.dir/guiapp.cpp.o.provides.build: src/gui/CMakeFiles/../../run.dir/guiapp.cpp.o

# Object files for target ../../run
__/__/run_OBJECTS = \
"CMakeFiles/../../run.dir/guiapp.cpp.o"

# External object files for target ../../run
__/__/run_EXTERNAL_OBJECTS =

src/gui/../../run: src/gui/CMakeFiles/../../run.dir/guiapp.cpp.o
src/gui/../../run: src/gui/CMakeFiles/../../run.dir/build.make
src/gui/../../run: src/gui/libFrm_main.a
src/gui/../../run: src/gui/libDlg_pattern.a
src/gui/../../run: src/gui/libDlg_colorModel.a
src/gui/../../run: src/gui/libDlg_topologicalMap.a
src/gui/../../run: src/imageView/libImageHolder.a
src/gui/../../run: src/drawing/libImageHolderTrack.a
src/gui/../../run: src/drawing/libImageHolderMaha.a
src/gui/../../run: src/drawing/libImageHolderTopolMaps.a
src/gui/../../run: src/classifiers/libPolyMahalanobis.a
src/gui/../../run: src/classifiers/libBackground.a
src/gui/../../run: src/classifiers/libPattern.a
src/gui/../../run: src/camModule/libCamModule.a
src/gui/../../run: src/camModule/libLogitechWrapper.a
src/gui/../../run: src/dip/libFrameObjects.a
src/gui/../../run: /usr/local/lib/libopencv_calib3d.so
src/gui/../../run: /usr/local/lib/libopencv_contrib.so
src/gui/../../run: /usr/local/lib/libopencv_core.so
src/gui/../../run: /usr/local/lib/libopencv_features2d.so
src/gui/../../run: /usr/local/lib/libopencv_flann.so
src/gui/../../run: /usr/local/lib/libopencv_gpu.so
src/gui/../../run: /usr/local/lib/libopencv_highgui.so
src/gui/../../run: /usr/local/lib/libopencv_imgproc.so
src/gui/../../run: /usr/local/lib/libopencv_legacy.so
src/gui/../../run: /usr/local/lib/libopencv_ml.so
src/gui/../../run: /usr/local/lib/libopencv_nonfree.so
src/gui/../../run: /usr/local/lib/libopencv_objdetect.so
src/gui/../../run: /usr/local/lib/libopencv_photo.so
src/gui/../../run: /usr/local/lib/libopencv_stitching.so
src/gui/../../run: /usr/local/lib/libopencv_ts.so
src/gui/../../run: /usr/local/lib/libopencv_video.so
src/gui/../../run: /usr/local/lib/libopencv_videostab.so
src/gui/../../run: src/dip/libLabeling.a
src/gui/../../run: src/dip/libDiffGray.a
src/gui/../../run: src/dip/libDilate.a
src/gui/../../run: src/dip/libTracking.a
src/gui/../../run: src/dip/libTrajectories.a
src/gui/../../run: src/gui/CMakeFiles/../../run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../run"
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/gui && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/../../run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/gui/CMakeFiles/../../run.dir/build: src/gui/../../run
.PHONY : src/gui/CMakeFiles/../../run.dir/build

src/gui/CMakeFiles/../../run.dir/requires: src/gui/CMakeFiles/../../run.dir/guiapp.cpp.o.requires
.PHONY : src/gui/CMakeFiles/../../run.dir/requires

src/gui/CMakeFiles/../../run.dir/clean:
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/gui && $(CMAKE_COMMAND) -P CMakeFiles/../../run.dir/cmake_clean.cmake
.PHONY : src/gui/CMakeFiles/../../run.dir/clean

src/gui/CMakeFiles/../../run.dir/depend:
	cd /home/lapix/Desktop/hmm/videoPolynom_wx_tracking && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lapix/Desktop/hmm/videoPolynom_wx_tracking /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/gui /home/lapix/Desktop/hmm/videoPolynom_wx_tracking /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/gui /home/lapix/Desktop/hmm/videoPolynom_wx_tracking/src/run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/gui/CMakeFiles/../../run.dir/depend

