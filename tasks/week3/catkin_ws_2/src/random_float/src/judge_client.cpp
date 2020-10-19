#include "ros/ros.h"
#include "random_float/Judge.h"
#include <cstdlib>
#include <ctime>
#define N 999

using namespace std;


int main(int argc, char **argv)
{
    ros::init(argc, argv, "random_float_client");
    srand(time(0));
    ros::Rate loop_rate(1);
    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<random_float::Judge>("random_float");
    random_float::Judge srv;
    while (ros::ok())
    {
        srv.request.num = (rand() % (N + 1) / float(N + 1));
        if (client.call(srv))
        {
            ROS_INFO("Random floating point number: %f", srv.request.num);
            if (srv.response.judgement)
            {
                ROS_INFO("YES");
            }
            else
            {
                ROS_INFO("NO");
            }
        }
        loop_rate.sleep();
    }
}