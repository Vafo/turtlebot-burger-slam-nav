#!/bin/bash

# Build the Dockerfile
# docker build -t nvidia_ros . -f dockerfile_nvidia_ros

# MODIFY BELOW (NOTE(jwd) - you may need to change the network id `wlp3s0` below)
export ROS_REMOTE_PC=$(ip a show dev wlo1 | awk '/inet / {print $2}' | awk -F"/" '{print $1}')  # for joesbox
export ROS_PORT=11311
export TURTLEBOT3_MODEL=burger
# END MODIFY 

# Start a terminal
docker run \
    -it \
    --net=host \
    --privileged \
    --gpus all \
    --env="NVIDIA_DRIVER_CAPABILITIES=all" \
    --env="DISPLAY=${DISPLAY}" \
    --env="QT_X11_NO_MITSHM=1" \
    --volume="/tmp/.X11-unix:/tmp/.X11-unix:rw" \
    \
    --env "ROS_MASTER_URI=http://$ROS_REMOTE_PC:$ROS_PORT" \
    --env "ROS_HOSTNAME=$ROS_REMOTE_PC" \
    --env "TURTLEBOT3_MODEL=$TURTLEBOT3_MODEL" \
    \
    nvidia_ros \
    bash
