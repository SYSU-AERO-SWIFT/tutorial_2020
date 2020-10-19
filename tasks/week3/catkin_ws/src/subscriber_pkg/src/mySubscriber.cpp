#include "ros/ros.h"
#include "publisher_pkg/theRandomNum.h"

void callback(const publisher_pkg::theRandomNum::ConstPtr& msg){
    ROS_INFO("The random num is %d\n", msg->data);
}

int main(int agrc, char** agrv){
    ros::init(agrc, agrv, "mySubscriber");
    ros::NodeHandle n;
    ros::Subscriber my_sub = n.subscribe("my_topic", 1000, callback);
    ros::spin();

    return 0;
}