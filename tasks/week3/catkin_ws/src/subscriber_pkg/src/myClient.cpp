#include "ros/ros.h"
#include "publisher_pkg/myRandom.h"
#include<cstdlib>

int main(int argc, char **argv){
    ros::init(argc, argv, "myClient");
    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<publisher_pkg::myRandom>("compare_the_random");
    publisher_pkg::myRandom srv;
    srand((unsigned)time(NULL));
    srv.request.random_num = _Float32(rand() % 1000000) / 1000000;
    ROS_INFO("The random num is %f\n", srv.request.random_num);
    if(!client.call(srv)){
        ROS_INFO("No. :(\n");
    }else{
        ROS_INFO("Yes. :)\n");
    }

    return 0;
}