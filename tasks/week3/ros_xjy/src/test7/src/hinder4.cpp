#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

#define pi 3.1415926

int main( int argc, char** argv )
{
  ros::init(argc, argv, "basic_shapes4");
  ros::NodeHandle n;
  ros::Rate r(10);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

  // Set our initial shape type to be a cube

int t=0;

  while (ros::ok())
  {
    visualization_msgs::Marker marker4;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker4.header.frame_id = "/my_frame";
    marker4.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker4.ns = "basic_shapes1";
    marker4.id = 4;

    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker4.type = visualization_msgs::Marker::SPHERE;

    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    marker4.action = visualization_msgs::Marker::ADD;

    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header


    marker4.pose.position.x = -5+2*cos((t+180)*pi/180);
    marker4.pose.position.y = 5+2*sin((t+180)*pi/180);
    marker4.pose.position.z = 0;

while (marker_pub.getNumSubscribers() < 1)
    {
      if (!ros::ok())
      {
        return 0;
      }
      ROS_WARN_ONCE("Please create a subscriber to the marker");
      sleep(1);
    }

    marker4.pose.orientation.x = 0.0;
    marker4.pose.orientation.y = 0.0;
    marker4.pose.orientation.z = 0.0;
    marker4.pose.orientation.w = 1.0;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker4.scale.x = 0.5;
    marker4.scale.y = 0.5;
    marker4.scale.z = 0.5;

    // Set the color -- be sure to set alpha to something non-zero!
    marker4.color.r = 255.0f;
    marker4.color.g = 1.0f;
    marker4.color.b = 128.0f;
    marker4.color.a = 1.0;
t++;

    marker4.lifetime = ros::Duration();
    marker_pub.publish(marker4);

    r.sleep();
}

  }
