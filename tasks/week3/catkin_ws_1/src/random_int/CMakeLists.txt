cmake_minimum_required(VERSION 3.0.2)
project(random_int)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  message_generation
)

add_message_files(
  FILES
  Num.msg
)

generate_messages()

catkin_package(
 INCLUDE_DIRS include
 LIBRARIES random_int
 CATKIN_DEPENDS roscpp message_runtime
 DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(talker src/talker.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})

add_executable(listener src/listener.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})