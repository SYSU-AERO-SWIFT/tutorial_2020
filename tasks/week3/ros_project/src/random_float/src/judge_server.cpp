#include "ros/ros.h"
#include "ramdon_float/Judge.h"

bool less(ramdom_float::Judge::Request  &req,
          random_float::Judge::Response &res)
{
    if (req.num < 0.5)
    {
        res.judgement = true;
    }
    else
    {
        res.judgement = false;
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "random_float_server");
    ros::NodeHandle n;

    ros::ServiceServer service = n.advertiseService("random_float", less);
    ros::spin();
    return 0;
}