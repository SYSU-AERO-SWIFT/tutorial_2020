#include<ros/ros.h>
#include "test/Message.h"

int main(int argc, char **argv)
{ 
//节点初始化
  ros::init(argc,argv, "person_publisher");

//定义句
ros::NodeHandle n;

//发布节点的名字，消息的类型，话题的名称
ros::Publisher person_info_pub=n.advertise<test::Message>("/Person_info",10);
ros::Rate loop_rate(1);

//产生随即数
srand((int)time(0));


while(ros::ok())
{
//定义消息的对象
test::Message person_msg;
//消息对象初始化
person_msg.rand=rand()%20;

//发布消息
person_info_pub.publish(person_msg);

ROS_INFO("Publish uniform Info: rand:%d",
      person_msg.rand);

loop_rate.sleep();
}
return 0;
}
