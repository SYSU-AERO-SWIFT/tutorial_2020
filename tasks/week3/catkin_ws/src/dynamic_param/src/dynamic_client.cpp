#include <ros/ros.h>
#include <dynamic_reconfigure/client.h>
#include <dynamic_param/myParamConfig.h>

void callback(const dynamic_param::myParamConfig &config){
    ROS_INFO("The Random num is %f, ",
        (float)config.random_num);
}

int main(int argc, char** argv){
    ros::init(argc, argv, "dynamic_client");
    dynamic_reconfigure::Client<dynamic_param::myParamConfig> client("dynamic_reconfigure_node", callback);
    dynamic_param::myParamConfig config;

    ros::Rate loop_rate(10);
    while(ros::ok()){
        srand((unsigned)time(NULL));
        config.random_num = _Float32(rand() % 1000000) / 1000000;
        client.setConfiguration(config);
        ros::spinOnce();
        loop_rate.sleep();
    }
    ROS_INFO("Beybey. :)\n");
    return 0;
}