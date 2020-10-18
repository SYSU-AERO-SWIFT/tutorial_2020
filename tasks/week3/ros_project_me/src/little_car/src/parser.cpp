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
//示例函数  使小车前进
//我们希望你能通过这个函数，模仿实现控制小车的速度，运动方向，转弯等动作
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
	   if(count<3000000000)
	       {  x +=0.003;
	          y=0.003*cos(x);
                  odom_trans.header.stamp = ros::Time::now();
                  odom_trans.transform.translation.x += velocity.x;  
                  odom_trans.transform.translation.y += y;
                  odom_trans.transform.translation.z += velocity.z;
                  position.x += velocity.x;      //更新小车的位置信息
                  position.y += y;
                  position.z += velocity.z;
                  if(judge)  odom_trans.transform.rotation = tf::createQuaternionMsgFromYaw(-1.57/300*count);
	          else odom_trans.transform.rotation = tf::createQuaternionMsgFromYaw(1.57/300*count);
	       }
	  else
		move_forward(odom_trans);
    return 0;
}

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
	velocity.x=0.003;    //速度设置，修改该参数可改变小车不同方向的速度
	velocity.y=0.0;
	velocity.z=0.0;
	int count=1;
	bool judge=true;
while(ros::ok())
 {  
	//订阅者从自定义publisher处订阅一个自定义的msg  
    sub=n.subscribe("turning_topic",3,turningCallback);
        if(judge2)
	{	
        /***********不重要的部分*********************/
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
        /********************************************/
		
	 if(count % 600==0) judge=!judge;
	 turning(odom_trans,count,judge);
	 count++;
	 pos_pub.publish(position);
         joint_pub.publish(joint_state);
	 add_noise(odom_trans);
         broadcaster.sendTransform(odom_trans);
         loop_rate.sleep();
         }
	else
	{
	/***********不重要的部分*********************/
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
        /********************************************/
        pos_pub.publish(position);
         joint_pub.publish(joint_state);
         //add_noise(odom_trans);
         broadcaster.sendTransform(odom_trans);
	 odom_trans.transform.rotation = tf::createQuaternionMsgFromYaw(0.0);
         loop_rate.sleep();

       	}
    ros::spinOnce();
 }
    return 0;
}

