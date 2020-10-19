#include<ros/ros.h>
#include "service_client/Random.h"
#include<random>
#include<ctime>

int main(int argc, char** argv)
{
	ros::init(argc, argv, "random_client");
	ros::NodeHandle node;

	ros::service::waitForService("/random_number");
	ros::ServiceClient randomClient = node.serviceClient<service_client::Random>("/random_number");

	std::default_random_engine e(time(nullptr));
        std::uniform_real_distribution<float> u(0, 1);

	service_client::Random srv;
	srv.request.random = u(e);

	ROS_INFO("Call service to evaluate random numbers: %f", srv.request.random);

	randomClient.call(srv);

	ROS_INFO("Random number: %f  Show result: %s", srv.request.random, (srv.response.result ? "Yes" : "No"));

	return 0;
}
