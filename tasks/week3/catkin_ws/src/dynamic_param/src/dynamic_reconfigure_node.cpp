#include <ros/ros.h>
#include <dynamic_reconfigure/server.h>
#include <dynamic_param/myParamConfig.h>

void callback(dynamic_param::myParamConfig &config, uint32_t level)
{   
    ROS_INFO("The random num is %f", 
        (float)config.random_num);
    if(config.random_num > 0.5)
        ROS_INFO("and the result is no. :( \n");
    else
        ROS_INFO("and the result is yes. :) \n");
}

int main(int argc, char **argv){
    ros::init(argc, argv, "dynamic_reconfigure_node");
    dynamic_reconfigure::Server<dynamic_param::myParamConfig> srv;
    dynamic_reconfigure::Server<dynamic_param::myParamConfig>::CallbackType f;
    f = boost::bind(&callback, _1, _2);
    srv.setCallback(f);
    ROS_INFO("Starting to spin...");
    ros::spin();
    return 0;
}