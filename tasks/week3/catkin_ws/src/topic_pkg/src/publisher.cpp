#include<ros/ros.h>
#include<topic_pkg/range.h>
#include<iostream>
using namespace std;
int main(int argc,char **argv)
{
 ros::init(argc,argv,"publisher_node");
 ros::NodeHandle nh;

 topic_pkg::range msg;
  ros::Publisher pub=nh.advertise<topic_pkg::range>("range_topic",10);
 ros::Rate loop_rate(0.5);
 while(ros::ok())
    {
msg.number=rand();
 pub.publish(msg);
loop_rate.sleep();
    }
return 0;
}

