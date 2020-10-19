cmake_minimum_required(VERSION 3.0.2)
project(random_float)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  genmsg
  message_generation
)

add_service_files(
  FILES
  Judge.srv
)

generate_messages()

catkin_package()

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(judge_server src/judge_server.cpp)
target_link_libraries(judge_server ${catkin_LIBRARIES})
add_dependencies(judge_server random_float_gencpp)

add_executable(judge_client src/judge_client.cpp)
target_link_libraries(judge_client ${catkin_LIBRARIES})
add_dependencies(judge_client random_float_gencpp)