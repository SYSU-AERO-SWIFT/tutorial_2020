

		
cmake_minimum_required(VERSION 2.8)
		
project (opencv)
		

		
find_package(OpenCV REQUIRED)
		

		
#加入头文件
		
include_directories(inc)
		

		
FILE(GLOB_RECURSE CURRENT_INCLUDE inc/opencv.h)
		
FILE(GLOB_RECURSE CURRENT_SOURCES src/func.cpp)
		

		
# 指定生成目标
		
add_executable(opencv test/readtest.cpp ${CURRENT_SOURCES} ${CURRENT_INCLUDE})
		

		
target_link_libraries(opencv ${OpenCV_LIBS})
