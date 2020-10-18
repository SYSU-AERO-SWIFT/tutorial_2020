#include<ros/ros.h>
#include "service_client/Random.h"

bool randomCallback(service_client::Random::Request &req, service_client::Random::Response &res)
{
	ROS_INFO("Recieve random number: %f", req.random);
	res.result = (req.random < 0.5);
	return true;
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "random_server");
	ros::NodeHandle node;

	ros::ServiceServer randomServer = node.advertiseService("/random_number", randomCallback);
	ROS_INFO("Ready to recieve random numbers.");
	ros::spin();

	return 0;
}
