# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "publisher_pkg: 1 messages, 1 services")

set(MSG_I_FLAGS "-Ipublisher_pkg:/home/big-big-yu/catkin_ws/src/publisher_pkg/msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(publisher_pkg_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/big-big-yu/catkin_ws/src/publisher_pkg/msg/theRandomNum.msg" NAME_WE)
add_custom_target(_publisher_pkg_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "publisher_pkg" "/home/big-big-yu/catkin_ws/src/publisher_pkg/msg/theRandomNum.msg" ""
)

get_filename_component(_filename "/home/big-big-yu/catkin_ws/src/publisher_pkg/srv/myRandom.srv" NAME_WE)
add_custom_target(_publisher_pkg_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "publisher_pkg" "/home/big-big-yu/catkin_ws/src/publisher_pkg/srv/myRandom.srv" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(publisher_pkg
  "/home/big-big-yu/catkin_ws/src/publisher_pkg/msg/theRandomNum.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/publisher_pkg
)

### Generating Services
_generate_srv_cpp(publisher_pkg
  "/home/big-big-yu/catkin_ws/src/publisher_pkg/srv/myRandom.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/publisher_pkg
)

### Generating Module File
_generate_module_cpp(publisher_pkg
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/publisher_pkg
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(publisher_pkg_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(publisher_pkg_generate_messages publisher_pkg_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/big-big-yu/catkin_ws/src/publisher_pkg/msg/theRandomNum.msg" NAME_WE)
add_dependencies(publisher_pkg_generate_messages_cpp _publisher_pkg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/big-big-yu/catkin_ws/src/publisher_pkg/srv/myRandom.srv" NAME_WE)
add_dependencies(publisher_pkg_generate_messages_cpp _publisher_pkg_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(publisher_pkg_gencpp)
add_dependencies(publisher_pkg_gencpp publisher_pkg_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS publisher_pkg_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(publisher_pkg
  "/home/big-big-yu/catkin_ws/src/publisher_pkg/msg/theRandomNum.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/publisher_pkg
)

### Generating Services
_generate_srv_eus(publisher_pkg
  "/home/big-big-yu/catkin_ws/src/publisher_pkg/srv/myRandom.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/publisher_pkg
)

### Generating Module File
_generate_module_eus(publisher_pkg
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/publisher_pkg
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(publisher_pkg_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(publisher_pkg_generate_messages publisher_pkg_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/big-big-yu/catkin_ws/src/publisher_pkg/msg/theRandomNum.msg" NAME_WE)
add_dependencies(publisher_pkg_generate_messages_eus _publisher_pkg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/big-big-yu/catkin_ws/src/publisher_pkg/srv/myRandom.srv" NAME_WE)
add_dependencies(publisher_pkg_generate_messages_eus _publisher_pkg_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(publisher_pkg_geneus)
add_dependencies(publisher_pkg_geneus publisher_pkg_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS publisher_pkg_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(publisher_pkg
  "/home/big-big-yu/catkin_ws/src/publisher_pkg/msg/theRandomNum.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/publisher_pkg
)

### Generating Services
_generate_srv_lisp(publisher_pkg
  "/home/big-big-yu/catkin_ws/src/publisher_pkg/srv/myRandom.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/publisher_pkg
)

### Generating Module File
_generate_module_lisp(publisher_pkg
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/publisher_pkg
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(publisher_pkg_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(publisher_pkg_generate_messages publisher_pkg_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/big-big-yu/catkin_ws/src/publisher_pkg/msg/theRandomNum.msg" NAME_WE)
add_dependencies(publisher_pkg_generate_messages_lisp _publisher_pkg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/big-big-yu/catkin_ws/src/publisher_pkg/srv/myRandom.srv" NAME_WE)
add_dependencies(publisher_pkg_generate_messages_lisp _publisher_pkg_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(publisher_pkg_genlisp)
add_dependencies(publisher_pkg_genlisp publisher_pkg_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS publisher_pkg_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(publisher_pkg
  "/home/big-big-yu/catkin_ws/src/publisher_pkg/msg/theRandomNum.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/publisher_pkg
)

### Generating Services
_generate_srv_nodejs(publisher_pkg
  "/home/big-big-yu/catkin_ws/src/publisher_pkg/srv/myRandom.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/publisher_pkg
)

### Generating Module File
_generate_module_nodejs(publisher_pkg
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/publisher_pkg
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(publisher_pkg_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(publisher_pkg_generate_messages publisher_pkg_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/big-big-yu/catkin_ws/src/publisher_pkg/msg/theRandomNum.msg" NAME_WE)
add_dependencies(publisher_pkg_generate_messages_nodejs _publisher_pkg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/big-big-yu/catkin_ws/src/publisher_pkg/srv/myRandom.srv" NAME_WE)
add_dependencies(publisher_pkg_generate_messages_nodejs _publisher_pkg_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(publisher_pkg_gennodejs)
add_dependencies(publisher_pkg_gennodejs publisher_pkg_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS publisher_pkg_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(publisher_pkg
  "/home/big-big-yu/catkin_ws/src/publisher_pkg/msg/theRandomNum.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/publisher_pkg
)

### Generating Services
_generate_srv_py(publisher_pkg
  "/home/big-big-yu/catkin_ws/src/publisher_pkg/srv/myRandom.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/publisher_pkg
)

### Generating Module File
_generate_module_py(publisher_pkg
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/publisher_pkg
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(publisher_pkg_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(publisher_pkg_generate_messages publisher_pkg_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/big-big-yu/catkin_ws/src/publisher_pkg/msg/theRandomNum.msg" NAME_WE)
add_dependencies(publisher_pkg_generate_messages_py _publisher_pkg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/big-big-yu/catkin_ws/src/publisher_pkg/srv/myRandom.srv" NAME_WE)
add_dependencies(publisher_pkg_generate_messages_py _publisher_pkg_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(publisher_pkg_genpy)
add_dependencies(publisher_pkg_genpy publisher_pkg_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS publisher_pkg_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/publisher_pkg)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/publisher_pkg
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(publisher_pkg_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/publisher_pkg)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/publisher_pkg
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(publisher_pkg_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/publisher_pkg)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/publisher_pkg
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(publisher_pkg_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/publisher_pkg)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/publisher_pkg
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(publisher_pkg_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/publisher_pkg)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/publisher_pkg\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/publisher_pkg
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(publisher_pkg_generate_messages_py std_msgs_generate_messages_py)
endif()
