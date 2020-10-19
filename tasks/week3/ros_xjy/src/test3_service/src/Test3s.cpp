/**
 * 该例程将执行/get_random服务，服务数据类型test3::Random
 */
 
#include <ros/ros.h>
#include "test3_service/Random.h"

// service回调函数，输入参数req，输出参数res
bool randomCallback(test3_service::Random::Request  &req,
         			test3_service::Random::Response &res)
{
    // 显示请求数据
    ROS_INFO("ramdom request: float random:%f", req.floatu);
// 设置反馈数据   
	if(req.floatu<0.5){
	res.ans = 1;
	}
	else{
	res.ans = 0;	
	}
    return true;
}

int main(int argc, char **argv)
{
    // ROS节点初始化
    ros::init(argc, argv, "Test3s");

    // 创建节点句柄
    ros::NodeHandle n;

    // 创建一个名为/get_random的server，注册回调函数personCallback
    ros::ServiceServer ram_service = n.advertiseService("/get_randnum", randomCallback);

    // 循环等待回调函数
    ROS_INFO("Ready to get random num.");
    ros::spin();

    return 0;
}


