
# Example ROS1 Package

This is an example ROS1 package demonstrating various features, including ROS nodes in C++ and Python, message generation, services, tests, and more.

## Features

- Publisher and Subscriber ROS Nodes in C++ and Python
- Service Server and Client in C++ and Python
- Google Test Integration for unit testing
- Basic setup to generate and test messages
- Examples of using `rostest` for testing ROS nodes

## File Structure

```
example_ros1_package/
│
├── CMakeLists.txt
├── package.xml
└── src/
    ├── publisher.cpp        # C++ Publisher Node
    ├── subscriber.cpp       # C++ Subscriber Node
    ├── service_server.cpp   # C++ Service Server Node
    ├── service_client.cpp   # C++ Service Client Node
    ├── test_example.cpp     # C++ Google Test Example
    └── publisher.py         # Python Publisher Node
    └── subscriber.py        # Python Subscriber Node
    └── service_server.py    # Python Service Server
    └── service_client.py    # Python Service Client
```

## Prerequisites

Before building the package, make sure the following packages are installed:

- ROS Noetic
- CMake 2.8.12 or higher
- GTest for unit testing

### Install Dependencies

```bash
sudo apt-get install ros-noetic-roscpp ros-noetic-rospy ros-noetic-std-msgs ros-noetic-message-generation ros-noetic-rostest
```

## Building the Package

1. Create and build the workspace:

```bash
cd ~/catkin_ws
catkin_make
```

2. Source the workspace setup file:

```bash
source devel/setup.bash
```

## Running the Nodes

### C++ Publisher and Subscriber

To run the C++ publisher and subscriber nodes:

1. Launch the Publisher:

```bash
rosrun example_ros1_package talker
```

2. Launch the Subscriber:

```bash
rosrun example_ros1_package listener
```

### C++ Service Server and Client

1. Launch the Service Server:

```bash
rosrun example_ros1_package add_two_ints_server
```

2. Launch the Service Client:

```bash
rosrun example_ros1_package add_two_ints_client
```

### Python Publisher and Subscriber

1. Launch the Python Publisher:

```bash
rosrun example_ros1_package publisher.py
```

2. Launch the Python Subscriber:

```bash
rosrun example_ros1_package subscriber.py
```

### Running Tests

To run the tests with Google Test:

```bash
catkin_make run_tests
```

## Contributions

Feel free to fork and contribute to this package. If you find any issues, please create a GitHub issue or submit a pull request.

## License

This package is released under the MIT License.
