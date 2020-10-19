#include<ros/ros.h>
#include<iostream>
#include<turning_pkg/turning.h>
using namespace std;
int main(int argc,char**argv)
{
        ros::init(argc,argv,"publisher_node");
        ros::NodeHandle nh;
        turning_pkg::turning msg;
        msg.sign=true;

        ros::Publisher pub=nh.advertise<turning_pkg::turning>("turning_topic",3);    ros::Rate loop_rate(1);
      while(ros::ok()){  
        pub.publish(msg);
        loop_rate.sleep();
       // std::cout<<"发布小车S弯指令"<<std::endl;
      }
return 0;
}

