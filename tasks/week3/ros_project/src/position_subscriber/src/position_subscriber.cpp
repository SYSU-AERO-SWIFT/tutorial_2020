#include <geometry_msgs/Point.h>
#include <ros/ros.h>

geometry_msgs::Point position;

void positionCallback(const geometry_msgs::Point::ConstPtr& msg)
{
    position.x = msg->x;
    position.y = msg->y;
    position.z = msg->z;
    ROS_INFO("Subcribe position: x:%f  y:%f  z:%f", msg->x, msg->y, msg->z);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "position_subscriber");
    ros::NodeHandle node;
    ros::Subscriber positionSub = node.subscribe("car_position", 1, positionCallback);

    ros::spin();
    
    return 0;
}


