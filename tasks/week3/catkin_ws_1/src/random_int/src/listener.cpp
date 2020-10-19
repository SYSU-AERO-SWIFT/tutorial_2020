#include "ros/ros.h"
#include "random_int/Num.h"


void callback(const random_int::Num::ConstPtr& msg)
{
  ROS_INFO("I heard: [%d]", msg->num);
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "Subscriber_task1");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("number", 1000, callback);
  ros::spin();
  return 0;
}