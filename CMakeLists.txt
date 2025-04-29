cmake_minimum_required(VERSION 2.8.12)
project(example_ros1_package)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
  rospy
)

add_service_files(
  FILES
  AddTwoInts.srv
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS roscpp std_msgs message_runtime rospy
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(talker src/publisher.cpp)
add_executable(listener src/subscriber.cpp)
add_executable(add_two_ints_server src/service_server.cpp)
add_executable(add_two_ints_client src/service_client.cpp)

add_dependencies(talker ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(talker ${catkin_LIBRARIES})

add_dependencies(listener ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(listener ${catkin_LIBRARIES})

add_dependencies(add_two_ints_server ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(add_two_ints_server ${catkin_LIBRARIES})

add_dependencies(add_two_ints_client ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(add_two_ints_client ${catkin_LIBRARIES})
