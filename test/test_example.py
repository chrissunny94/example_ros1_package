#!/usr/bin/env python
import rospy
import rostest
from std_msgs.msg import String

def callback(data):
    rospy.loginfo("Received message: %s", data.data)

def test_example():
    rospy.init_node('test_example')
    rospy.Subscriber('chatter', String, callback)
    pub = rospy.Publisher('chatter', String, queue_size=10)
    
    # Test publishing a message
    pub.publish("Hello ROS")
    rospy.sleep(1)
    assert rospy.is_shutdown() == False

if __name__ == '__main__':
    rostest.rosrun('example_ros1_package', 'test_example', test_example)
