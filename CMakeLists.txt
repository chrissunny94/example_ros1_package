cmake_minimum_required(VERSION 2.8.12)
project(example_ros1_package)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
  rospy
  rostest
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

# Include directories
include_directories(
  ${catkin_INCLUDE_DIRS}
)

# Add executables for your ROS nodes
add_executable(talker src/publisher.cpp)
add_executable(listener src/subscriber.cpp)
add_executable(add_two_ints_server src/service_server.cpp)
add_executable(add_two_ints_client src/service_client.cpp)

# Add dependencies and link libraries
add_dependencies(talker ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(talker ${catkin_LIBRARIES})

add_dependencies(listener ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(listener ${catkin_LIBRARIES})

add_dependencies(add_two_ints_server ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(add_two_ints_server ${catkin_LIBRARIES})

add_dependencies(add_two_ints_client ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(add_two_ints_client ${catkin_LIBRARIES})

# Find Google Test
find_package(GTest REQUIRED)

# Add test executables using catkin_add_gtest
catkin_add_gtest(test_example test/test_example.cpp)

# Link Google Test libraries and catkin libraries to the test executable
target_link_libraries(test_example
  ${catkin_LIBRARIES}
  ${GTEST_LIBRARIES}
)

# Optional: If using Google Test with CTest, make sure you enable testing
enable_testing()
