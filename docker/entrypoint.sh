#!/bin/bash
 
# Source ROS and Catkin workspaces
source /opt/ros/noetic/setup.bash
if [ -f /turtlebot3_ws/devel/setup.bash ]
then
  source /turtlebot3_ws/devel/setup.bash
fi
echo "Sourced Catkin workspace!"
 
# Set environment variables
# export GAZEBO_MODEL_PATH=$GAZEBO_MODEL_PATH:$(rospack find tb3_worlds)/models
 
# Execute the command passed into this entrypoint
exec "$@"
