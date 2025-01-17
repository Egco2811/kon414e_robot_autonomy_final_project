cmake_minimum_required(VERSION 3.0.2)
project(circle_motion)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  tf
)

## Declare a catkin package
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES circle_motion
  CATKIN_DEPENDS geometry_msgs roscpp rospy tf
#  DEPENDS system_lib
)

## Specify additional locations of header files
include_directories(
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ executable
add_executable(circle_motion_node src/circle_motion_node.cpp)
add_executable(odom src/odom.cpp)

## Add dependencies for the executable
add_dependencies(circle_motion_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Link libraries to the executable
target_link_libraries(circle_motion_node
  ${catkin_LIBRARIES}
)
target_link_libraries(odom ${catkin_LIBRARIES})


#############
## Install ##
#############

## Mark executables for installation
install(TARGETS circle_motion_node
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

## Mark other files for installation (e.g., launch files)
install(DIRECTORY launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

