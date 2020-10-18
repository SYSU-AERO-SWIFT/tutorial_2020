#include<ros/ros.h>
#include<random>
#include<ctime>
#include "pub_sub/Random.h"

int main(int argc, char** argv)
{
	ros::init(argc, argv, "random_publisher");
	ros::NodeHandle n;

	ros::Publisher randomPub = n.advertise<pub_sub::Random>("/random_number", 10);
	ros::Rate loop_rate(1);

	std::default_random_engine e(time(nullptr));
	std::uniform_real_distribution<float> u(0, 100);

	while(ros::ok())
	{
		pub_sub::Random random_msg;
		random_msg.start = 0;
		random_msg.end = 100;
		random_msg.random = u(e);

		randomPub.publish(random_msg);

		ROS_INFO("Publish random number: (%f, %f) --> %f", random_msg.start, random_msg.end, random_msg.random);

		loop_rate.sleep();
	}

	return 0;
}
