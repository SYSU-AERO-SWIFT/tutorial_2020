/**
 * 该例程将执行/show_person服务，服务数据类型learning_service::Person
 */
 
#include <ros/ros.h>
#include "server_client/Random.h"

// service回调函数，输入参数req，输出参数res
bool numberCallback(server_client::Random::Request  &req,
         			server_client::Random::Response &res)
{

	// 设置反馈数据
	if(req.number < 0.5)
		res.answer = true;

    return true;
}

int main(int argc, char **argv)
{
    // ROS节点初始化
    ros::init(argc, argv, "number_server");

    // 创建节点句柄
    ros::NodeHandle n;

    // 创建一个名为/show_person的server，注册回调函数personCallback
    ros::ServiceServer number_service = n.advertiseService("/show_number", numberCallback);

    // 循环等待回调函数
    ROS_INFO("Ready to random number informtion.");
    ros::spin();

    return 0;
}


