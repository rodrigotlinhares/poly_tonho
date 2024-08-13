cmake_minimum_required(VERSION 2.6)
project(POLYMCPP)

find_package(OpenCV)
find_package(wxWidgets)

INCLUDE(${wxWidgets_USE_FILE})

set(CMAKE_CXX_FLAGS "-g -Wall")

add_subdirectory(src/gui)
add_subdirectory(src/util)
add_subdirectory(src/classifiers)
add_subdirectory(src/drawing)
add_subdirectory(src/imageView)
add_subdirectory(src/camModule)
add_subdirectory(src/dip)
add_subdirectory(src/detector)
