xterm -e "roslaunch turtlebot_gazebo turtlebot_ulisworld.launch" &
sleep 5
xterm -e "roslaunch turtlebot_gazebo custom_amcl.launch" &
sleep 5
xterm -e "rosrun rviz rviz -d pathfinder.rviz" &
sleep 5
xterm -e "rosrun send_goals send_one_goal" &
sleep 5
xterm -e "rosrun add_markers add_markers"
