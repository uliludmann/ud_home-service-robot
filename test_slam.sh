xterm -e " roslaunch turtlebot_gazebo turtlebot_ulisworld.launch" &
sleep 7
xterm -e "rosrun gmapping slam_gmapping" &
sleep 7
xterm -e "roslaunch turtlebot_rviz_launchers view_navigation.launch " &
sleep 5
xterm -e "roslaunch turtlebot_teleop keyboard_teleop.launch"

