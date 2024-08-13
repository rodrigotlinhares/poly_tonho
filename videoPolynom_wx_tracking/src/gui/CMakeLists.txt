include_directories (${POLYMCPP_SOURCE_DIR}/src) 

# Make sure the linker can find the Hello library once it is built.
link_directories (${POLYMCPP_BINARY_DIR}/src) 

# Add executable called "helloDemo" that is built from the source files
# "demo.cxx" and "demo_b.cxx". The extensions are automatically found. 
add_executable (../../run guiapp.cpp)

# Link the executable to the library.
target_link_libraries (../../run Frm_main)
target_link_libraries (../../run Dlg_pattern)
target_link_libraries (../../run Dlg_colorModel)
target_link_libraries (../../run Dlg_topologicalMap)

target_link_libraries (../../run ImageHolder)
target_link_libraries (../../run ImageHolderTrack)
target_link_libraries (../../run ImageHolderMaha)
target_link_libraries (../../run ImageHolderTopolMaps)
target_link_libraries (../../run PolyMahalanobis)
target_link_libraries (../../run Background)
target_link_libraries (../../run Pattern) 
target_link_libraries (../../run CamModule)
target_link_libraries (../../run LogitechWrapper)
target_link_libraries (../../run FrameObjects)
target_link_libraries (../../run Detector)

TARGET_LINK_LIBRARIES(../../run ${OpenCV_LIBS})
TARGET_LINK_LIBRARIES(../../run ${wxWidgets_LIBRARIES})

add_library(Frm_main frm_main.cpp)
add_library(Dlg_pattern dlg_pattern.cpp)
add_library(Dlg_colorModel dlg_colormodel.cpp)
add_library(Dlg_topologicalMap dlg_topologicalmap.cpp)
