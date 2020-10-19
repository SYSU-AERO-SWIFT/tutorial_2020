#include "ros/ros.h"
#include "publisher_pkg/myRandom.h"

bool judge(publisher_pkg::myRandom::Request &req,
           publisher_pkg::myRandom::Response &res)
{
    if(req.random_num - 0.5 > 1e-6)
       return false;
    return true; 
}

int main(int argc, char** argv){
    ros::init(argc, argv, "myService");
    ros::NodeHandle n;

    ros::ServiceServer server = n.advertiseService("compare_the_random", judge);
    ros::spin();

    return 0;
}