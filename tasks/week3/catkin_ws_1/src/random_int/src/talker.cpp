#include "ros/ros.h"
#include "random_int/Num.h"
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char **argv)
{
  srand(time(0));
  ros::init(argc, argv, "Publisher_task1");
  ros::NodeHandle n;
  ros::Publisher num_pub = n.advertise<random_int::Num>("number", 1000);
  ros::Rate loop_rate(1);
  while (ros::ok())
  {

    random_int::Num number;
    number.num = rand();
    ROS_INFO("%d", number.num);
    num_pub.publish(number);
    ros::spinOnce();
    loop_rate.sleep();
  }


  return 0;
}