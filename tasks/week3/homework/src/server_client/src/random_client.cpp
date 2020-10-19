/**
 * 该例程将请求/show_number服务，服务数据类型server_cilent::Random
 */

#include <ros/ros.h>
#include "server_client/Random.h"
#include <time.h>
#include <cstdlib>

float createNum()
{
    srand(time(0));
    return rand()%100/(float)101;       //返回0到1之间的随机数
}
int main(int argc, char** argv)
{
    // 初始化ROS节点
	ros::init(argc, argv, "number_client");

    // 创建节点句柄
	ros::NodeHandle node;

    // 发现/show_number服务后，创建一个服务客户端，连接名为/show_number的service
	ros::service::waitForService("/show_number");
	ros::ServiceClient number_client = node.serviceClient<server_client::Random>("/show_number");

    // 初始化server_cilent::Random的请求数据
	server_client::Random srv;
	ros::Rate loop_rate(0.5);
	while(1)
	{
		srv.request.number = createNum();//创建随机数

    	// 请求服务调用

		number_client.call(srv);

	// 显示服务调用结果
		ROS_INFO("The random number is: %f", srv.request.number);
		if(srv.response.answer)
		{

			ROS_INFO("Whether the number is less than 0.5: Yes");
		}	
		else{
			ROS_INFO("Whether the number is less than 0.5: No");
		}

		loop_rate.sleep();
	}
	return 0;
};


