/**
 * 该程序将发布/number_info话题，自定义消息类型random_create::RandomNum
 */
#include <cstdlib>
#include <ros/ros.h>
#include "random_create/RandomNum.h"

int main(int argc, char **argv)
{
    // ROS节点初始化
    ros::init(argc, argv, "randNum_publisher");

    // 创建节点句柄
    ros::NodeHandle n;

    // 创建一个Publisher，发布名为/number_info的topic，消息类型为random_create::RandomNum，队列长度10
    ros::Publisher number_info_pub = n.advertise<random_create::RandomNum>("/number_info", 10);

    // 设置循环的频率
    ros::Rate loop_rate(1);

    int count = 0;
    while (ros::ok())
    {
       //需要包含头文件#include <cstdlib>
    	random_create::RandomNum number_msg;
		number_msg.randNum = rand()%100;

        // 发布消息
		number_info_pub.publish(number_msg);

       	ROS_INFO("Publish RandomNumber:%d", number_msg.randNum);

        // 按照循环频率延时
        loop_rate.sleep();
    }

    return 0;
}
