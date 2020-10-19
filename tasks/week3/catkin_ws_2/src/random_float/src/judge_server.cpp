#include "ros/ros.h"
#include <dynamic_reconfigure/server.h>
#include <boost/bind.hpp>
#include "random_float/my_cfgConfig.h"
#include "random_float/Judge.h"
float threshold = 0.5f;
void dynamicCallback(random_float::my_cfgConfig:: &config)
bool less(ramdom_float::Judge::Request  &req,
          random_float::Judge::Response &res)
{
    if (req.num < threshold)
    {
        res.judgement = true;
    }
    else
    {
        res.judgement = false;
    }
    return true;
}

void dynamicCallback(random_float::my_cfgConfig:: &config)
{
    threshold = config.threshold;
}


int main(int argc, char **argv)
{
    ros::init(argc, argv, "random_float_server");
    ros::NodeHandle n;

    ros::ServiceServer service = n.advertiseService("random_float", less);
    dynamic_reconfigure::Server<random_float::my_cfgConfig> server;
    dynamic_reconfigure::Server<random_float::my_cfgConfig>::CallbackType f;

    f = boost::bind(&dynamicCallback, _1);
    server.setCallback(f);

    ros::spin();
    return 0;
}