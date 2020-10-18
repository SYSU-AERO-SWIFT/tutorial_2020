#include<ros/ros.h>
#include"test2/Person.h"

bool personCallback(test2::Person::Request &req,
		test2::Person::Response &res)
{
	//判断结果，并且返回判断
	if(req.rand<0.5)
		res.ans=1;
	else
		res.ans=0;
return true;
}

int main(int argc, char **argv)
{
	//节点初始化
	ros::init(argc,argv,"person_servicer");

	//创建句柄
	ros::NodeHandle n;

	ros::ServiceServer person_service=n.advertiseService("/answer",personCallback);
	//循环等待
	ROS_INFO("Ready");
	ros::spin();
	return 0;
}

