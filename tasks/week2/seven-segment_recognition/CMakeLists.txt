cmake_minimum_required(VERSION 3.1)

project(week2)

find_package(OpenCV REQUIRED)


message(STATUS "OpenCV library status:")
message(STATUS "    config: ${OpenCV_DIR}")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")


add_executable(test main.cpp recognition.cpp recognition.h)


target_link_libraries(test PRIVATE ${OpenCV_LIBS})
