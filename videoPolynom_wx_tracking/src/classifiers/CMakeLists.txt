include_directories (${POLYMCPP_SOURCE_DIR}/src) 

#building just a library. 
add_library(PolyMahalanobis polyMahalanobis.cpp)
add_library(Background background.cpp)
add_library(Pattern pattern.cpp)

