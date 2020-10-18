#include<ros/ros.h>
#include<topic_pkg/range.h>
void rangeCallback(const topic_pkg::range::ConstPtr & msg)
{
        std::cout<<"随机数字为："<<msg->number<<std::endl;
}

int main(int argc,char**argv)
{
        ros::init(argc,argv,"subscriber_node");
        ros::NodeHandle n;
        ros::Subscriber sub=n.subscribe("range_topic",30,rangeCallback);
        ros::spin();
        return 0;

}

