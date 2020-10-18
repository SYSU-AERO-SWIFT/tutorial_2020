#include <ros/ros.h>
#include <dynamic_reconfigure/server.h>
#include "dynamic_param_server/randomParamConfig.h"

void callback(dynamic_param_server::randomParamConfig &config, uint32_t level) {
	ROS_INFO("Reconfigure Request: %f", config.random_param);
}

int main(int argc, char **argv) 
{
   ros::init(argc, argv, "dynamic_param_server");

   dynamic_reconfigure::Server<dynamic_param_server::randomParamConfig> server;
   dynamic_reconfigure::Server<dynamic_param_server::randomParamConfig>::CallbackType f;

   f = boost::bind(&callback, _1, _2);
   server.setCallback(f);

   ROS_INFO("Spinning node");
   ros::spin();
   return 0;
}
