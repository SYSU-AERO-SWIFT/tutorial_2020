cmake_minimum_required(VERSION 2.8.3)
project(dynamic_refg)
 
find_package(catkin REQUIRED COMPONENTS
  dynamic_reconfigure
  roscpp
  rospy
  std_msgs
)
 
 generate_dynamic_reconfigure_options(
   cfg/My_cfg.cfg
 )
 
catkin_package(
#  INCLUDE_DIRS include
   LIBRARIES dynamic_refg
   CATKIN_DEPENDS dynamic_reconfigure roscpp rospy std_msgs
#  DEPENDS system_lib
)
 
 
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)
 
 
add_executable(node src/node.cpp)
add_dependencies(node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(node
   ${catkin_LIBRARIES}
 )
 
