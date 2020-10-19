/**
 * 该例程将订阅/number_info话题，自定义消息类型randomcreate::RandomNum
 */
 
#include <ros/ros.h>
#include "random_create/RandomNum.h"

// 接收到订阅的消息后，会进入消息回调函数
void numberInfoCallback(const random_create::RandomNum::ConstPtr& msg)
{
    // 将接收到的消息打印出来
    ROS_INFO("Subcribe number:%d", 
			  msg->randNum);
}

int main(int argc, char **argv)
{
    // 初始化ROS节点
    ros::init(argc, argv, "number_subscriber");

    // 创建节点句柄
    ros::NodeHandle n;

    // 创建一个Subscriber，订阅名为/number_info的topic，注册回调函数numberInfoCallback
    ros::Subscriber number_info_sub = n.subscribe("/number_info", 10,numberInfoCallback);

    // 循环等待回调函数
    ros::spin();

    return 0;
}
