#include "ros/ros.h"
#include "example_ros1_package/AddTwoInts.h"

bool add(example_ros1_package::AddTwoInts::Request &req,
         example_ros1_package::AddTwoInts::Response &res)
{
  res.sum = req.a + req.b;
  ROS_INFO("Request: x=%ld, y=%ld, sum=%ld", req.a, req.b, res.sum);
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_two_ints_server");
  ros::NodeHandle n;
  ros::ServiceServer service = n.advertiseService("add_two_ints", add);
  ROS_INFO("Ready to add two ints.");
  ros::spin();
  return 0;
}
