# CMake 最低版本号要求

cmake_minimum_required(VERSION 2.8)
project (Digital_realise)

find_package(OpenCV REQUIRED)

#加入头文件
include_directories(inc)

FILE(GLOB_RECURSE CURRENT_INCLUDE inc/NumRec.h)
FILE(GLOB_RECURSE CURRENT_SOURCES src/NumRec.cpp) 

# 指定生成目标
add_executable(Digital_realise test/demo.cpp ${CURRENT_SOURCES} ${CURRENT_INCLUDE})

target_link_libraries(Digital_realise ${OpenCV_LIBS})
