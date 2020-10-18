#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

#define pi 3.1415926

int main( int argc, char** argv )
{
  ros::init(argc, argv, "basic_shapes0");
  ros::NodeHandle n;
  ros::Rate r(10);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

  // Set our initial shape type to be a cube

int t=0;// 更新位置

  while (ros::ok())
  {
    visualization_msgs::Marker marker1;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker1.header.frame_id = "/my_frame";
    marker1.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker1.ns = "my_frame";
    marker1.id = 0;

    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker1.type = visualization_msgs::Marker::CUBE;

    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    marker1.action = visualization_msgs::Marker::ADD;

    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header


    marker1.pose.position.x = 0;
    marker1.pose.position.y = 0;
    marker1.pose.position.z = 0;

while (marker_pub.getNumSubscribers() < 1)
    {
      if (!ros::ok())
      {
        return 0;
      }
      ROS_WARN_ONCE("Please create a subscriber to the marker");
      sleep(1);
    }
 
    marker1.pose.orientation.x = 0.0;
    marker1.pose.orientation.y = 0.0;
    marker1.pose.orientation.z = 0.0;
    marker1.pose.orientation.w = 1.0;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker1.scale.x = 20;
    marker1.scale.y = 20;
    marker1.scale.z = 0.1;

    // Set the color -- be sure to set alpha to something non-zero!
    marker1.color.r = 0.0f;
    marker1.color.g = 0.3f;
    marker1.color.b = 0.3f;
    marker1.color.a = 1.0;
t++;

    marker1.lifetime = ros::Duration();
    marker_pub.publish(marker1);
    r.sleep();

  }
}
