# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "exercise1: 1 messages, 1 services")

set(MSG_I_FLAGS "-Iexercise1:/home/anifan/tutorial_2020/tasks/week3/ros_exercise/src/exercise1/msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(exercise1_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/anifan/tutorial_2020/tasks/week3/ros_exercise/src/exercise1/msg/random.msg" NAME_WE)
add_custom_target(_exercise1_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "exercise1" "/home/anifan/tutorial_2020/tasks/week3/ros_exercise/src/exercise1/msg/random.msg" ""
)

get_filename_component(_filename "/home/anifan/tutorial_2020/tasks/week3/ros_exercise/src/exercise1/srv/number.srv" NAME_WE)
add_custom_target(_exercise1_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "exercise1" "/home/anifan/tutorial_2020/tasks/week3/ros_exercise/src/exercise1/srv/number.srv" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(exercise1
  "/home/anifan/tutorial_2020/tasks/week3/ros_exercise/src/exercise1/msg/random.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/exercise1
)

### Generating Services
_generate_srv_cpp(exercise1
  "/home/anifan/tutorial_2020/tasks/week3/ros_exercise/src/exercise1/srv/number.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/exercise1
)

### Generating Module File
_generate_module_cpp(exercise1
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/exercise1
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(exercise1_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(exercise1_generate_messages exercise1_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/anifan/tutorial_2020/tasks/week3/ros_exercise/src/exercise1/msg/random.msg" NAME_WE)
add_dependencies(exercise1_generate_messages_cpp _exercise1_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/anifan/tutorial_2020/tasks/week3/ros_exercise/src/exercise1/srv/number.srv" NAME_WE)
add_dependencies(exercise1_generate_messages_cpp _exercise1_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(exercise1_gencpp)
add_dependencies(exercise1_gencpp exercise1_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS exercise1_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(exercise1
  "/home/anifan/tutorial_2020/tasks/week3/ros_exercise/src/exercise1/msg/random.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/exercise1
)

### Generating Services
_generate_srv_eus(exercise1
  "/home/anifan/tutorial_2020/tasks/week3/ros_exercise/src/exercise1/srv/number.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/exercise1
)

### Generating Module File
_generate_module_eus(exercise1
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/exercise1
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(exercise1_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(exercise1_generate_messages exercise1_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/anifan/tutorial_2020/tasks/week3/ros_exercise/src/exercise1/msg/random.msg" NAME_WE)
add_dependencies(exercise1_generate_messages_eus _exercise1_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/anifan/tutorial_2020/tasks/week3/ros_exercise/src/exercise1/srv/number.srv" NAME_WE)
add_dependencies(exercise1_generate_messages_eus _exercise1_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(exercise1_geneus)
add_dependencies(exercise1_geneus exercise1_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS exercise1_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(exercise1
  "/home/anifan/tutorial_2020/tasks/week3/ros_exercise/src/exercise1/msg/random.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/exercise1
)

### Generating Services
_generate_srv_lisp(exercise1
  "/home/anifan/tutorial_2020/tasks/week3/ros_exercise/src/exercise1/srv/number.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/exercise1
)

### Generating Module File
_generate_module_lisp(exercise1
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/exercise1
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(exercise1_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(exercise1_generate_messages exercise1_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/anifan/tutorial_2020/tasks/week3/ros_exercise/src/exercise1/msg/random.msg" NAME_WE)
add_dependencies(exercise1_generate_messages_lisp _exercise1_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/anifan/tutorial_2020/tasks/week3/ros_exercise/src/exercise1/srv/number.srv" NAME_WE)
add_dependencies(exercise1_generate_messages_lisp _exercise1_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(exercise1_genlisp)
add_dependencies(exercise1_genlisp exercise1_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS exercise1_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(exercise1
  "/home/anifan/tutorial_2020/tasks/week3/ros_exercise/src/exercise1/msg/random.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/exercise1
)

### Generating Services
_generate_srv_nodejs(exercise1
  "/home/anifan/tutorial_2020/tasks/week3/ros_exercise/src/exercise1/srv/number.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/exercise1
)

### Generating Module File
_generate_module_nodejs(exercise1
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/exercise1
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(exercise1_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(exercise1_generate_messages exercise1_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/anifan/tutorial_2020/tasks/week3/ros_exercise/src/exercise1/msg/random.msg" NAME_WE)
add_dependencies(exercise1_generate_messages_nodejs _exercise1_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/anifan/tutorial_2020/tasks/week3/ros_exercise/src/exercise1/srv/number.srv" NAME_WE)
add_dependencies(exercise1_generate_messages_nodejs _exercise1_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(exercise1_gennodejs)
add_dependencies(exercise1_gennodejs exercise1_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS exercise1_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(exercise1
  "/home/anifan/tutorial_2020/tasks/week3/ros_exercise/src/exercise1/msg/random.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/exercise1
)

### Generating Services
_generate_srv_py(exercise1
  "/home/anifan/tutorial_2020/tasks/week3/ros_exercise/src/exercise1/srv/number.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/exercise1
)

### Generating Module File
_generate_module_py(exercise1
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/exercise1
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(exercise1_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(exercise1_generate_messages exercise1_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/anifan/tutorial_2020/tasks/week3/ros_exercise/src/exercise1/msg/random.msg" NAME_WE)
add_dependencies(exercise1_generate_messages_py _exercise1_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/anifan/tutorial_2020/tasks/week3/ros_exercise/src/exercise1/srv/number.srv" NAME_WE)
add_dependencies(exercise1_generate_messages_py _exercise1_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(exercise1_genpy)
add_dependencies(exercise1_genpy exercise1_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS exercise1_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/exercise1)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/exercise1
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(exercise1_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/exercise1)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/exercise1
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(exercise1_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/exercise1)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/exercise1
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(exercise1_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/exercise1)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/exercise1
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(exercise1_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/exercise1)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/exercise1\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/exercise1
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(exercise1_generate_messages_py std_msgs_generate_messages_py)
endif()
