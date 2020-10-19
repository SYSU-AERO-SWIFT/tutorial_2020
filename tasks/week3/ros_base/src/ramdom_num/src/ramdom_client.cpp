
/**
 * 该例程将请求/ramdom_num服务，服务数据类型ramdom_num::ram
 */

#include <ros/ros.h>
#include "ramdom_num/ram.h"
int main(int argc, char** argv)
{
    // 初始化ROS节点
	ros::init(argc, argv, "ramdom_client");

    // 创建节点句柄
	ros::NodeHandle node;

    // 发现/ramdom_server服务后，创建一个服务客户端，连接名为/ramdom_server的service
	ros::service::waitForService("/ramdom_num");
	ros::ServiceClient ram_client = node.serviceClient<ramdom_num::ram>("/ramdom_num");
	srand((int)time(0));  // 产生随机种子
    // 初始化learning_service::Person的请求数据
	while(1){
	ramdom_num::ram srv;
	
	srv.request.floatu = (rand()%10000)/10000.0; //产生0，1的浮点数


    // 请求服务调用
	ROS_INFO("Call service to ram[ram:%f]", 
			srv.request.floatu );

	ram_client.call(srv);

	// 显示服务调用结果
if(srv.response.result==1){
	ROS_INFO("ram : %f,is less than 0.5?:%s", srv.request.floatu,"Yes");
}
else{
	ROS_INFO("ram : %f,is less than 0.5?:%s", srv.request.floatu,"No");
}

}


	return 0;
};


