#include "ros/ros.h"
#include "publisher_pkg/theRandomNum.h"
#include <cstdlib>

int main(int argc, char** argv){
    ros::init(argc, argv, "myPublisher");
    ros::NodeHandle n;
    ros::Publisher my_topic = n.advertise<publisher_pkg::theRandomNum>("my_topic", 1000);
    ros::Rate loop_rate(10);

    while(ros::ok()){
        int temp = rand();
        publisher_pkg::theRandomNum msg;
        msg.data = temp;
        // ROS_INFO("%d", msg.data);
        my_topic.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}