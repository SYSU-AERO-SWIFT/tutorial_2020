#include<ros/ros.h>
#include "test1/Random.h"

int main(int argc, char **argv)
{
	//ROS节点初始化
	ros::init(argc,argv, "Test1");

	//创建节点句柄
	ros::NodeHandle n;

	//发布节点的名字，消息的类型，话题的名称
	ros::Publisher test_rand_pub=n.advertise<test1::Random>("/test_info",10);
	ros::Rate loop_rate(10);

	//产生一个随机数
	srand((float)time(0));


	while(ros::ok())
	{
		//定义消息对象
		test1::Random person_msg;
		//初始化消息
		person_msg.randnum=rand()%100;
		//发布消息
		test_rand_pub.publish(person_msg);
		ROS_INFO("Publish uniform Info: rand:%d",
      		person_msg.randnum);

		//按照循环频率延时
		loop_rate.sleep();
	}
	return 0;
}
