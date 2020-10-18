#include<ros/ros.h>
#include"test2/Person.h"

int main(int argc,char **argv)
{
	//初始化节点
	ros::init(argc,argv,"person_client");
       //创建句柄
ros::NodeHandle n;

//等待服务
//ros::service::waitForService("/answer");
ros::ServiceClient person_client=n.serviceClient<test2::Person>("/answer");

//生成随机数
srand((int)time(0));

//初始化请求数据
test2::Person service;
service.request.rand=rand()%1000/1000.0;

//请求数据调用
person_client.call(service);

//判断结果

if(service.response.ans==1)
ROS_INFO("the rand:%f,%s",service.request.rand,"yes");
else
ROS_INFO("the rand:%f,%s",service.request.rand,"no");
return 0;

}

