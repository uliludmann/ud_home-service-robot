/*
 * Copyright (c) 2010, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Willow Garage, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

// %Tag(FULLTEXT)%
// %Tag(INCLUDES)%
#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <nav_msgs/Odometry.h>
// %EndTag(INCLUDES)%

int state_ = 0;

void odomChecker(const nav_msgs::Odometry::ConstPtr& msg) {
	//ROS_INFO("odom received");
	//if state 0 check if position 1 is reached
	if (state_ == 0){
	if (abs(msg -> pose.pose.position.x - 0.0)< 0.05 ) {
		if	(abs(msg -> pose.pose.position.y - 10.0) < 0.05 )
		{
			ROS_INFO("POSITION 1(Y)");
			state_ = 1;
		}
	} 
	}
	
	//if state 1 check if pos2 is reached
	if (state_ == 1) {
	if (abs(msg -> pose.pose.position.x - 10.0)< 0.05 ) {
		if	(abs(msg -> pose.pose.position.y + 1.0) < 0.05 )
		{
			ROS_INFO("POSITION 2(Y)");
			state_ = 2;
		}
	}
	}
	//ROS_INFO("%d", state_);
	
}
    

// %Tag(INIT)%
int main( int argc, char** argv )
{
  ros::init(argc, argv, "basic_shapes");
  ros::NodeHandle n;
  ros::Rate r(1);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
// %EndTag(INIT)%

//subscribe odom topic
	ros::Subscriber odom_sub = n.subscribe("/odom", 1000, odomChecker);

  // Set our initial shape type to be a cube
// %Tag(SHAPE_INIT)%
  uint32_t shape = visualization_msgs::Marker::CUBE;
// %EndTag(SHAPE_INIT)%


    visualization_msgs::Marker marker1;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker1.header.frame_id = "/map";
    marker1.header.stamp = ros::Time::now();
// %EndTag(MARKER_INIT)%

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
// %Tag(NS_ID)%
    marker1.ns = "basic_shapes";
    marker1.id = 0;
// %EndTag(NS_ID)%

    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
// %Tag(TYPE)%
    marker1.type = shape;
// %EndTag(TYPE)%

    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
// %Tag(ACTION)%
    marker1.action = visualization_msgs::Marker::ADD;
// %EndTag(ACTION)%

    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
// %Tag(POSE)%
    marker1.pose.position.x = 0;
    marker1.pose.position.y = 10.0;
    marker1.pose.position.z = 0;
    marker1.pose.orientation.x = 0.0;
    marker1.pose.orientation.y = 0.0;
    marker1.pose.orientation.z = 0.0;
    marker1.pose.orientation.w = 1.0;
// %EndTag(POSE)%

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
// %Tag(SCALE)%
    marker1.scale.x = 1.0;
    marker1.scale.y = 1.0;
    marker1.scale.z = 1.0;
// %EndTag(SCALE)%

    // Set the color -- be sure to set alpha to something non-zero!
// %Tag(COLOR)%
    marker1.color.r = 0.0f;
    marker1.color.g = 1.0f;
    marker1.color.b = 0.0f;
    marker1.color.a = 1.0;
// %EndTag(COLOR)%

// %Tag(LIFETIME)%
    marker1.lifetime = ros::Duration();
// %EndTag(LIFETIME)%

visualization_msgs::Marker marker2;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker2.header.frame_id = "/map";
    marker2.header.stamp = ros::Time::now();
// %EndTag(MARKER_INIT)%

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
// %Tag(NS_ID)%
    marker2.ns = "basic_shapes";
    marker2.id = 0;
// %EndTag(NS_ID)%

    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
// %Tag(TYPE)%
    marker2.type = shape;
// %EndTag(TYPE)%

    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    marker2.action = visualization_msgs::Marker::ADD;
    marker2.pose.position.x = 10.0;
    marker2.pose.position.y = -1.0;
    marker2.pose.position.z = 0;
    marker2.pose.orientation.x = 0.0;
    marker2.pose.orientation.y = 0.0;
    marker2.pose.orientation.z = 0.0;
    marker2.pose.orientation.w = 1.0;
    marker2.scale.x = 1.0;
    marker2.scale.y = 1.0;
    marker2.scale.z = 1.0;
    marker2.color.r = 0.0f;
    marker2.color.g = 1.0f;
    marker2.color.b = 0.0f;
    marker2.color.a = 1.0;
    marker2.lifetime = ros::Duration();   
    
    
    
    
    while(ros::ok()){
    //simple statemachine
	switch (state_){ 
    case 0:
    	marker_pub.publish(marker1);
    		ROS_INFO("CASE 0");
    	break;
    case 1:
    ros::Duration(5.0).sleep()
    	marker1.action = visualization_msgs::Marker::DELETE;
    	marker_pub.publish(marker1);
    		ROS_INFO("CASE 1");
    	break;
    case 2:
    ros::Duration(0.5).sleep();
      marker_pub.publish(marker2);
      ROS_INFO("CASE 2");
      break;
    }
    ros::spinOnce();
 }
    
    
	
  
}
// %EndTag(FULLTEXT)%