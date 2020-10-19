
/**
 * 该例程将订阅/ramdom_info话题，自定义消息类型ramdom_num::uni
 */
 
#include <ros/ros.h>
#include "ramdom_num/uni.h"

// 接收到订阅的消息后，会进入消息回调函数
void personInfoCallback(const ramdom_num::uni::ConstPtr& msg)
{
    // 将接收到的消息打印出来
    ROS_INFO("Subcribe uniform Info: num:%d", 
				  msg->intu);
}

int main(int argc, char **argv)
{
    // 初始化ROS节点
    ros::init(argc, argv, "uni_subscriber");

    // 创建节点句柄
    ros::NodeHandle n;

    // 创建一个Subscriber，订阅名为/ramdom_info的topic，注册回调函数personInfoCallback
    ros::Subscriber uni_info_sub = n.subscribe("/ramdom_info", 10, personInfoCallback);

    // 循环等待回调函数
    ros::spin();

    return 0;
}
