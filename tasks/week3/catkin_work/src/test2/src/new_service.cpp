#include<ros/ros.h>
#include"test2/Person.h"


int in;

bool personCallback(test2::Person::Request &req,
		test2::Person::Response &res)
{
	//判断结果，并且返回判断
	if(in<0.5)
		res.ans=1;
	else
		res.ans=0;
return true;
}



int main(int argc, char **argv)
{
   //节点初始化
	ros::init(argc,argv,"new_servicer");
	ros::NodeHandle n;

	ros::param::get("rand",in);
	ros::ServiceServer person_service=n.advertiseService("/answer", personCallback);

	ROS_INFO("Ready");
	ros::spin();
	return 0;
}

