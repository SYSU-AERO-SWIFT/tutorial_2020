

/**
 * 该例程将执行/ramdom_num服务，服务数据类型ramdom_num::ram
 */
 
#include <ros/ros.h>
#include "ramdom_num/ram.h"

// service回调函数，输入参数req，输出参数res
bool personCallback(ramdom_num::ram::Request  &req,
         			ramdom_num::ram::Response &res)
{
    // 显示请求数据
    ROS_INFO("ramdom request: float ram:%f", req.floatu);
// 设置反馈数据    
	if(req.floatu<0.5){
	res.result = 1;
	}
	else{
	res.result = 0;	
	}
    return true;
}

int main(int argc, char **argv)
{
    // ROS节点初始化
    ros::init(argc, argv, "ramdom_server");

    // 创建节点句柄
    ros::NodeHandle n;

    // 创建一个名为/ramdom_num的server，注册回调函数personCallback
    ros::ServiceServer ram_service = n.advertiseService("/ramdom_num", personCallback);

    // 循环等待回调函数
    ROS_INFO("Ready to get ram num.");
    ros::spin();

    return 0;
}


