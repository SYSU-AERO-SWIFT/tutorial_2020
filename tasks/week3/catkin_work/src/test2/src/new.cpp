#include<ros/ros.h>
#include"test2/Person.h"


int in;

int main(int argc, char **argv)
{
   //节点初始化
	ros::init(argc,argv,"new_servicer");
	ros::NodeHandle n;

if (ros::param::has("/rand"))
ROS_INFO("EWCWI");
else
ROS_INFO("nowh");

	n.getParam("rand",in);
	if(in<0.5)
	n.setParam("ans",1);
	else
	n.setParam("ans",0);

	ROS_INFO("Ready");
	ros::spin();
	return 0;
}
