include_directories (${POLYMCPP_SOURCE_DIR}/src) 

#building just a library. 
add_library(ImageHolderMaha cycImageHolderMaha.cpp)
add_library(ImageHolderTrack cycImageHolderTrack.cpp)
add_library(ImageHolderTopolMaps cycImageHolderTopolMaps.cpp)
