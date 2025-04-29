# example_ros1_package

A beginner-friendly **ROS1** package demonstrating:

- Publishing and subscribing to topics
- Calling and serving services (`AddTwoInts`)
- Implementations in **C++**, **Python**
- A simple **web interface** using `roslibjs` to interact with ROS


```
rosdep install --from-paths src --ignore-src -r -y
sudo apt-get update
sudo apt-get install libgtest-dev cmake

```

---

## 📦 Package Structure

```
example_ros1_package/
├── CMakeLists.txt
├── package.xml
├── srv/
│   └── AddTwoInts.srv
├── src/
│   ├── publisher.cpp
│   ├── subscriber.cpp
│   ├── service_server.cpp
│   └── service_client.cpp
├── scripts/
│   ├── publisher.py
│   ├── subscriber.py
│   ├── service_server.py
│   └── service_client.py
├── web/
│   └── ros_web_example.html
└── launch/
    └── demo.launch
```

---

## ✅ Build Instructions

```bash
cd ~/catkin_ws/src
git clone https://github.com/chrissunny94/example_ros1_package.git
cd ~/catkin_ws
catkin_make
source devel/setup.bash
```

---

## 🚀 Usage

### Topic Publisher / Subscriber

#### C++:
```bash
rosrun example_ros1_package talker
rosrun example_ros1_package listener
```

#### Python:
```bash
rosrun example_ros1_package publisher.py
rosrun example_ros1_package subscriber.py
```

---

### Service Server / Client

#### C++:
```bash
rosrun example_ros1_package add_two_ints_server
rosrun example_ros1_package add_two_ints_client
```

#### Python:
```bash
rosrun example_ros1_package service_server.py
rosrun example_ros1_package service_client.py
```

---

### 🌐 Web Interface (HTML + JavaScript)

#### Requirements:
- `rosbridge_server`

Install and run:
```bash
sudo apt install ros-noetic-rosbridge-server
roslaunch rosbridge_server rosbridge_websocket.launch
```

#### Serve the Web Page:
```bash
cd ~/catkin_ws/src/example_ros1_package/web
python3 -m http.server 8080
```

Then open [http://localhost:8080/ros_web_example.html](http://localhost:8080/ros_web_example.html) in your browser.

---

## 🧪 Launch All (Optional)

Add a `launch/demo.launch`:

```xml
<launch>
  <node pkg="example_ros1_package" type="talker" name="talker" output="screen"/>
  <node pkg="example_ros1_package" type="listener" name="listener" output="screen"/>
  <node pkg="example_ros1_package" type="add_two_ints_server" name="service_server" output="screen"/>
</launch>
```

Then run:
```bash
roslaunch example_ros1_package demo.launch
```

---

## 📚 Dependencies

- ROS Noetic (or any ROS1 distro)
- `roscpp`, `std_msgs`, `message_generation`
- `rosbridge_server` (for web interface)

---

## 👨‍💻 Author

Chris Sunny — [@chrissunny94](https://github.com/chrissunny94)

---

## 📝 License

This project is licensed under the MIT License.
