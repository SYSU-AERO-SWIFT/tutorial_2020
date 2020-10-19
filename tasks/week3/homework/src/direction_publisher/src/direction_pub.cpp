/*
 * 程序将发布/little_car/cmd话题，消息类型little_car ::turn_msg
 */

#include<direction_publisher/direction_msg.h>
#include <ros/ros.h>
int main(int argc, char **argv)

{
	// ROS节点初始化
	ros::init(argc, argv, "direction_publisher");
	// 创建节点句柄
	ros::NodeHandle n;
	ros::Publisher littlecar_vel_pub = n.advertise<direction_publisher ::direction_msg>("/little_car/cmd", 100);
	// 设置循环的频率,20hz

	ros::Rate loop_rate(20);

	while (ros::ok())
	{
		direction_publisher ::direction_msg vel_msg;

		vel_msg.state = 1;//state = 0 停止 ，1前进，2左转，3右转
		// 发布消息
		littlecar_vel_pub.publish(vel_msg);
		ROS_INFO("state is %d",vel_msg.state);
		// 按照循环频率延时
		loop_rate.sleep();

	}



	return 0;

}
