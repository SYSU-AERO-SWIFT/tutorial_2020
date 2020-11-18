cmake_minimum_required(VERSION 2.8)
project( IdentQR )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( IdentQR identQR.cpp )
target_link_libraries( IdentQR ${OpenCV_LIBS} )

