#include<ros/ros.h>
#include "test1/Random.h"

void testCallback (const test1::Random::ConstPtr& msg)
{
	ROS_INFO("subscriber message: rand:%d", msg->randnum);
}


int main(int argc, char **argv)
{
	//节点初始化
	ros::init(argc,argv,"Test1sub");
	//创建节点句柄
	ros::NodeHandle n;
	//创建一个Subscriber,订阅名为test_info的话题，注册回调函数testCallback
	ros::Subscriber test_rand__sub=n.subscribe("/test_info",10,testCallback);
	ros::spin();
	return 0;
}
