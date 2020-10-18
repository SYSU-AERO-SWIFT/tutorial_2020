#include<ros/ros.h>
#include "test/Message.h"

void personCallback (const test::Message::ConstPtr& msg)
{
	ROS_INFO("subscriber message: rand:%d", msg->rand);
}


int main(int argc, char **argv)
{
//节点初始化
	ros::init(argc,argv,"person_subscriber");
	ros::NodeHandle n;
//订阅话题为"/Person_info"话题的消息
	ros::Subscriber person_sub=n.subscribe("/Person_info",10,personCallback);
	ros::spin();
	return 0;
}

