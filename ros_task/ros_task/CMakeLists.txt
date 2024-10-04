cmake_minimum_required(VERSION 3.0.2)
project(ros_task)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  sensor_msgs
  control_msgs
  hardware_interface
  transmission_interface
  controller_manager
  gazebo_ros
)

catkin_package(
  CATKIN_DEPENDS roscpp rospy std_msgs sensor_msgs control_msgs hardware_interface transmission_interface controller_manager gazebo_ros
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(joint_position_publisher src/joint_position_publisher.cpp)
target_link_libraries(joint_position_publisher ${catkin_LIBRARIES})



