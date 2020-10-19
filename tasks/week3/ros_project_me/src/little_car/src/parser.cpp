#include <urdf/model.h>
#include <string>
#include <sensor_msgs/JointState.h>
#include <tf/transform_broadcaster.h>
#include <geometry_msgs/Point.h>
#include <ros/ros.h>
#include <random>
#include <iomanip>
#include<cmath>
#include"turning_pkg/turning.h"

geometry_msgs::Point position; //小车的位置信息
geometry_msgs::Point velocity; //小车的速度控制
using namespace std;
//该函数使小车前进
int move_forward(geometry_msgs::TransformStamped &odom_trans)
{

        odom_trans.header.stamp = ros::Time::now();
        odom_trans.transform.translation.x += velocity.x;	//小车 x 方向的移动 每次加上velocity.x的距离
        odom_trans.transform.translation.y += velocity.y;
        odom_trans.transform.translation.z += velocity.z;
		position.x += velocity.x;	//更新小车的位置信息
		position.y += velocity.y;
		position.z += velocity.z;
		odom_trans.transform.rotation = tf::createQuaternionMsgFromYaw(-1.57); //小车的角度设置
		return 0;
}
bool judge2=false; //bool型变量，其值被订阅的msg控制
int count;
float x,y;
//函数的作用是使小车走S路线
int turning(geometry_msgs::TransformStamped &odom_trans,int &count,bool & judge)
{
	   if(count<300000000000)
	       {  x +=0.005;
	          y=0.005*cos(x);
                  odom_trans.header.stamp = ros::Time::now();
                  odom_trans.transform.translation.x += velocity.x;  
                  odom_trans.transform.translation.y += y;
                  odom_trans.transform.translation.z += velocity.z;
                  position.x += velocity.x;      //更新小车的位置信息
                  position.y += y;
                  position.z += velocity.z;
		  // 通过传递进来的bool值来判断小车的方向
                  if(judge)  odom_trans.transform.rotation = tf::createQuaternionMsgFromYaw(-1.57/300*count);
	          else odom_trans.transform.rotation = tf::createQuaternionMsgFromYaw(1.57/300*count);
	       }
	  else//如果上面的if函数调整为if（count<300），则会使小车进行右转
		move_forward(odom_trans);
    return 0;
}
// 订阅者的回调函数，控制judge2的值
void turningCallback(const turning_pkg::turning::ConstPtr & msg)
{
if(msg->sign==true)judge2=true;
}
//添加噪声
int add_noise(geometry_msgs::TransformStamped &odom_trans)
{
		float sigma = velocity.x + velocity.y + velocity.z;
		double noise[3];
		random_device rd;
		mt19937 gen(rd());
		normal_distribution<double> normal(0,sigma);
		for(int i=0;i<3;i++)
		{		
			noise[i] = normal(gen);
		}
		odom_trans.header.stamp = ros::Time::now();
        odom_trans.transform.translation.x += noise[0];					//小车 x 方向的移动 每次加上velocity.x的距离
        odom_trans.transform.translation.y += noise[1];
        odom_trans.transform.translation.z += noise[2];
		position.x += noise[0];											//更新小车的位置信息
		position.y += noise[1];
		position.z += noise[2];
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "state_publisher");
    ros::NodeHandle n;
    ros::Publisher joint_pub = n.advertise<sensor_msgs::JointState>("joint_states", 1);
	ros::Publisher pos_pub = n.advertise<geometry_msgs::Point>("car_position",1); //小车的位置消息发布
	
	//声明一个订阅者
	ros::Subscriber sub;

  
      	tf::TransformBroadcaster broadcaster;
    ros::Rate loop_rate(30);
    // message declarations
    geometry_msgs::TransformStamped odom_trans;
    sensor_msgs::JointState joint_state;
    odom_trans.header.frame_id = "odom";
    odom_trans.child_frame_id = "base_link";
	velocity.x=0.005;    //速度设置，修改该参数可改变小车不同方向的速度
	velocity.y=0.0;
	velocity.z=0.0;
	int count=1;
	bool judge=true;
while(ros::ok())
 {  
	//订阅者从自定义publisher处订阅一个自定义的msg  
    sub=n.subscribe("turning_topic",3,turningCallback);
        if(judge2)//如果订阅者收到了发布者的消息，则judge2会变为true
	{	
		joint_state.header.stamp = ros::Time::now();
        joint_state.name.resize(4);
        joint_state.position.resize(4);
        joint_state.name[0] ="base_to_wheel_1";
        joint_state.position[0] = 0;
        joint_state.name[1] ="base_to_wheel_2";
        joint_state.position[1] = 0;
        joint_state.name[2] ="base_to_wheel_3";
        joint_state.position[2] = 0;
		joint_state.name[3] ="base_to_wheel_4";
		joint_state.position[3] = 0;
		
	 if(count % 600==0) judge=!judge;//当count增加到600时，小车刚好走完一个半圆，此时改变judge的值以控制小车有正确的方向
	 turning(odom_trans,count,judge);//调用函数，使小车走S弯
	 count++;
	 pos_pub.publish(position);
         joint_pub.publish(joint_state);
	 add_noise(odom_trans);
         broadcaster.sendTransform(odom_trans);
         loop_rate.sleep();
         }
	else//如果订阅者未收到消息，则小车不会动
	{
                joint_state.header.stamp = ros::Time::now();
        joint_state.name.resize(4);
        joint_state.position.resize(4);
        joint_state.name[0] ="base_to_wheel_1";
        joint_state.position[0] = 0;
        joint_state.name[1] ="base_to_wheel_2";
        joint_state.position[1] = 0;
        joint_state.name[2] ="base_to_wheel_3";
        joint_state.position[2] = 0;
                joint_state.name[3] ="base_to_wheel_4";
                joint_state.position[3] = 0;
        
        pos_pub.publish(position);
         joint_pub.publish(joint_state);
         broadcaster.sendTransform(odom_trans);
	 odom_trans.transform.rotation = tf::createQuaternionMsgFromYaw(0.0);
         loop_rate.sleep();

       	}
    ros::spinOnce();
 }
    return 0;
}

