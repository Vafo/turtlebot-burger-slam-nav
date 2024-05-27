# TURTLEBOT 3 SLAM AND NAVIGATION

The objective of this package is to explore and fine-tune navigation parameters, alongside with adding a feature which enables adding waypoints directly from rviz.

## Team: Harmony
- U2010105 - Juraboev Sardor
- U2010156 - Kurbanov Djakhongir
- U2010168 - Mirzakhmetov Mukhammadsobir
- U2010189 - Nematov Olimjon
- U2010233 - Safokhujaev Vafokhon

## Prerequisites:
- ROS Noetic
- Catkin
- CMake 3.0+
- C++ compiler (should support C++11 at least)
- ROS packages: turtlebot3_navigation, turtlebot3_slam, turtlebot3_bringup, turtlebot3_description, turtlebot3_teleop, rviz
- Cartographer (is a default slam method. For installation instructions refer to [link](https://google-cartographer-ros.readthedocs.io/en/latest/compilation.html) and for the fix of the build error refer to [link](https://github.com/cartographer-project/cartographer_ros/issues/1726))
- Gazebo (optional)

## Compiling
To compile package, clone it to the src/ directory of catkin workspace, return to the workspace directory and run:

```
catkin_make_isolated --force-cmake
```

Build of cartographer may fail several times and crash tabs opened in the browser randomly. To finish build in such case just try to rerun the above command until the build succeeds.

After successful build execute:

```
source devel_isolated/setup.bash
```

## SLAM
To run slam node execute command:

```
roslaunch cd_harmony slam.launch
```

If you are using Gazeb simulation use the following command:

```
roslaunch cd_harmony slam.launch configuration_basename:=turtlebot3_lds_2d_gazebo.lua
```

Open another terminal and execute:

```
roslaunch turtlebot3_teleop turtlebot3_teleop_key.launch
```

Now you are set for scanning the map.

After map scanning is finished execute:

```
rosrun map_server map_saver -f <path_where_you_want_to_save_map>/<map_name>
```

## Navigation
To run navigation node execute the following command with optimized navigation parameters:

```
roslaunch cd_harmony navigation.launch map_file:=<path_to_map>/<map.yaml> param_folder:=cur
```

If you want to use default navigation parameters just omit setting param_folder argument.

Pose estimation should be carried out first. First set approximate robot location and try to run turtlebot3_teleop_key and rotate 2-5 seconds (use 'a'  or 'd' key).

'waypoint' plugin may be used to set a waypoint. A new waypoint will appear in the left panel of the waypoints panel. 
To form a group of waypoints use 'New Group' button and enter waypoint name. Select newly created waypoint group and add points which should in this group by selecting each point separately and clicking '+ to group' button. Newly added waypoint will appear in right panel after some delay. This means that a waypoint is added successfully. To delete a waypoint from a group, select the waypoint and click on '- from group' button.
