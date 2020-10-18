/**
 * 该例程将请求/get_randnum服务，服务数据类型test3_service::Random
 */

#include <ros/ros.h>
#include "test3_service/Random.h"
int main(int argc, char** argv)
{
    // 初始化ROS节点
	ros::init(argc, argv, "Test3c");

    // 创建节点句柄
	ros::NodeHandle node;

    // 发现/ramdom_server服务后，创建一个服务客户端，连接名为/ramdom_server的service
	ros::service::waitForService("/get_randnum");
			ros::ServiceClient ram_client=node.serviceClient<test3_service::Random>("/get_randnum");

    	// 初始化learning_service::Person的请求数据
	test3_service::Random srv;
	srand((int)time(0));  // 产生随机种子
	srv.request.floatu = (rand()%1000)/1000.0; //产生0，1的浮点数


        // 请求服务调用
	ROS_INFO("Call service to ramdom[ramdom:%f]",
			srv.request.floatu );

	ram_client.call(srv);

	// 显示服务调用结果
if(srv.response.ans==1){
	ROS_INFO("ramdom : %f,is less than 0.5?:%s", srv.request.floatu,"Yes");
}
else{
	ROS_INFO("ramdom : %f,is less than 0.5?:%s", srv.request.floatu,"No");
}




	return 0;
};
