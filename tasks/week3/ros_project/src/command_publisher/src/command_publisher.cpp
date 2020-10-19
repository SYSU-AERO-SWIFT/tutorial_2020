#include <ros/ros.h>
#include "command_publisher/Command.h"
#include<cmath>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "command_publisher");
    ros::NodeHandle node;

    ros::Publisher commandPub = node.advertise<command_publisher::Command>("/velocity_command", 10);

    ros::Rate loop_rate(20);
    int count = 0;
    while (ros::ok())
    {
        command_publisher::Command msg;
	/*****************************
	//直角转向折线行走
        int n = count / 100;
	msg.theta = 90 * std::pow(-1, n+1);
	if(msg.theta > 0)
	{
                msg.x = 0.002;
                msg.y = 0;
		msg.z = 0;
	}
	else
	{
		msg.x = 0;
		msg.y = 0.002;
		msg.z = 0;
	}
        *******************************/
	//走正弦曲线
	msg.y = 0.005;
	msg.x = std::cos(0.005*count)*0.005;
	msg.z = 0;
	msg.theta = std::sin(0.005*count) / (std::pow(std::cos(0.005*count), 2) + 1);
        
	commandPub.publish(msg);

        ROS_INFO("Publish velocity command: x:%f  y:%f  z:%f", msg.x, msg.y, msg.z);
	count++;
        loop_rate.sleep();
    }

    return 0;
}
