cmake_minimum_required(VERSION 2.8)
project( MyCanny )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( MyCanny myCanny.cpp )
target_link_libraries( MyCanny ${OpenCV_LIBS} )

