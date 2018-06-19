xterm -e "roslaunch turtlebot_gazebo turtlebot_ulisworld.launch" &
sleep 7
xterm -e "roslaunch turtlebot_gazebo mapping.launch" &
sleep 7
xterm -e "roslaunch turtlebot_rviz_launchers view_navigation.launch " &
sleep 7
xterm -e "rosrun wall_follower wall_follower_node" &
sleep 5
