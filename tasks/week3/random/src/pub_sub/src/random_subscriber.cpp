#include<ros/ros.h>
#include "pub_sub/Random.h"

void randomCallback(const pub_sub::Random::ConstPtr& msg)
{
	ROS_INFO("Subscribe random number: (%f, %f) --> %f", msg->start, msg->end, msg->random);
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "random_subscriber");
	ros::NodeHandle n;

	ros::Subscriber randomSub = n.subscribe("/random_number", 10, randomCallback);

	ros::spin();

	return 0;
}
