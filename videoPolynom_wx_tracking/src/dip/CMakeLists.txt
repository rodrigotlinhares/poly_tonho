#building just a library. 
add_library(Labeling labeling.cpp)
add_library(DiffGray diffGray.cpp)
add_library(FrameObjects frameObjects.cpp)
add_library(Dilate dilate.cpp)
add_library(Tracking tracking.cpp)
add_library(Trajectories trajectories.cpp)

target_link_libraries (FrameObjects Labeling)
target_link_libraries (FrameObjects DiffGray)
target_link_libraries (FrameObjects Dilate)
target_link_libraries (FrameObjects Tracking)
target_link_libraries (FrameObjects Trajectories)
