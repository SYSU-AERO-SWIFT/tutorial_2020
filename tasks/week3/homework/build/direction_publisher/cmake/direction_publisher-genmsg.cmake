# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "direction_publisher: 1 messages, 0 services")

set(MSG_I_FLAGS "-Idirection_publisher:/home/sae/homework/src/direction_publisher/msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(direction_publisher_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/sae/homework/src/direction_publisher/msg/direction_msg.msg" NAME_WE)
add_custom_target(_direction_publisher_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "direction_publisher" "/home/sae/homework/src/direction_publisher/msg/direction_msg.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(direction_publisher
  "/home/sae/homework/src/direction_publisher/msg/direction_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/direction_publisher
)

### Generating Services

### Generating Module File
_generate_module_cpp(direction_publisher
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/direction_publisher
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(direction_publisher_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(direction_publisher_generate_messages direction_publisher_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/sae/homework/src/direction_publisher/msg/direction_msg.msg" NAME_WE)
add_dependencies(direction_publisher_generate_messages_cpp _direction_publisher_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(direction_publisher_gencpp)
add_dependencies(direction_publisher_gencpp direction_publisher_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS direction_publisher_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(direction_publisher
  "/home/sae/homework/src/direction_publisher/msg/direction_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/direction_publisher
)

### Generating Services

### Generating Module File
_generate_module_eus(direction_publisher
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/direction_publisher
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(direction_publisher_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(direction_publisher_generate_messages direction_publisher_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/sae/homework/src/direction_publisher/msg/direction_msg.msg" NAME_WE)
add_dependencies(direction_publisher_generate_messages_eus _direction_publisher_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(direction_publisher_geneus)
add_dependencies(direction_publisher_geneus direction_publisher_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS direction_publisher_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(direction_publisher
  "/home/sae/homework/src/direction_publisher/msg/direction_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/direction_publisher
)

### Generating Services

### Generating Module File
_generate_module_lisp(direction_publisher
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/direction_publisher
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(direction_publisher_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(direction_publisher_generate_messages direction_publisher_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/sae/homework/src/direction_publisher/msg/direction_msg.msg" NAME_WE)
add_dependencies(direction_publisher_generate_messages_lisp _direction_publisher_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(direction_publisher_genlisp)
add_dependencies(direction_publisher_genlisp direction_publisher_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS direction_publisher_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(direction_publisher
  "/home/sae/homework/src/direction_publisher/msg/direction_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/direction_publisher
)

### Generating Services

### Generating Module File
_generate_module_nodejs(direction_publisher
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/direction_publisher
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(direction_publisher_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(direction_publisher_generate_messages direction_publisher_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/sae/homework/src/direction_publisher/msg/direction_msg.msg" NAME_WE)
add_dependencies(direction_publisher_generate_messages_nodejs _direction_publisher_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(direction_publisher_gennodejs)
add_dependencies(direction_publisher_gennodejs direction_publisher_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS direction_publisher_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(direction_publisher
  "/home/sae/homework/src/direction_publisher/msg/direction_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/direction_publisher
)

### Generating Services

### Generating Module File
_generate_module_py(direction_publisher
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/direction_publisher
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(direction_publisher_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(direction_publisher_generate_messages direction_publisher_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/sae/homework/src/direction_publisher/msg/direction_msg.msg" NAME_WE)
add_dependencies(direction_publisher_generate_messages_py _direction_publisher_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(direction_publisher_genpy)
add_dependencies(direction_publisher_genpy direction_publisher_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS direction_publisher_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/direction_publisher)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/direction_publisher
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(direction_publisher_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/direction_publisher)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/direction_publisher
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(direction_publisher_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/direction_publisher)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/direction_publisher
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(direction_publisher_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/direction_publisher)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/direction_publisher
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(direction_publisher_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/direction_publisher)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/direction_publisher\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/direction_publisher
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(direction_publisher_generate_messages_py std_msgs_generate_messages_py)
endif()
