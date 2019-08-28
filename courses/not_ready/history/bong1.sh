sudo apt-get install ros-kinetic-image-transport
sudo apt-get install ros-kinetic-image-publisher
sudo apt-get install ros-kinetic-vision-msgs

cd ~/catkin_ws/src
git clone https://github.com/dusty-nv/ros_deep_learning
cd ../
catkin_make
