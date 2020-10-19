
/**
 * 该例程设置/读取ramdom_num中的参数
 */
#include <ros/ros.h>
#include <ramdom_num/TutorialsConfig.h>
#include "ramdom_num/ram.h"

int main(int argc, char **argv)
{
	int red, green, blue;

    // ROS节点初始化
    ros::init(argc, argv, "parameter_config");

    // 创建节点句柄
    ros::NodeHandle node;
	
	srand((int)time(0));  // 产生随机种子
	double u=(rand()%10000)/10000.0 ;
	// 设置随即浮点参数
	ros::param::set("/double_ram",u);//设置为0到1间的浮点数
	
	ROS_INFO("Set double_rams%f",u);
	
	 // 发现/ramdom_server服务后，创建一个服务客户端，连接名为/ramdom_server的service
	ros::service::waitForService("/ramdom_num");
	ros::ServiceClient ram_client = node.serviceClient<ramdom_num::ram>("/ramdom_num");
        ramdom_num::ram srv;
	srv.request.floatu = u;
	ram_client.call(srv);
	
	// 显示服务调用结果
if(srv.response.result==1){
	ROS_INFO("ram : %f,is less than 0.5?:%s", srv.request.floatu,"Yes");
}
else{
	ROS_INFO("ram : %f,is less than 0.5?:%s", srv.request.floatu,"No");
}	
	
	sleep(1);

    return 0;
}
