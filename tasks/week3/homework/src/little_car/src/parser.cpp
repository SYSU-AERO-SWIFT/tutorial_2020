#include <urdf/model.h>
#include <string>
#include <sensor_msgs/JointState.h>
#include <tf/transform_broadcaster.h>
#include <geometry_msgs/Point.h>
#include <ros/ros.h>
#include<little_car/direction_msg.h>    //自定义message
#include <random>
#include <iomanip>
#include<cmath>
geometry_msgs::Point position; //小车的位置信息
geometry_msgs::Point velocity; //小车的速度控制
using namespace std;
int my_state;//用于接收指令，state = 0 停止 ，1前进，2左转，3右转
//示例函数  使小车前进
//我们希望你能通过这个函数，模仿实现控制小车的速度，运动方向，转弯等动作
int move_forward(geometry_msgs::TransformStamped &odom_trans)
{

	odom_trans.header.stamp = ros::Time::now();
	odom_trans.transform.translation.x += velocity.x;					//小车 x 方向的移动 每次加上velocity.x的距离
	odom_trans.transform.translation.y += velocity.y;
	odom_trans.transform.translation.z += velocity.z;
	position.x += velocity.x;											//更新小车的位置信息
	position.y += velocity.y;
	position.z += velocity.z;
	odom_trans.transform.rotation = tf::createQuaternionMsgFromYaw(0.0); //小车的角度设置
	return 0;
}

//小车停止
int move_stop(geometry_msgs::TransformStamped &odom_trans)
{

	velocity.x = 0.0;    //速度设置，修改该参数可改变小车不同方向的速度
	velocity.y = 0.0;
	velocity.z = 0.0;
	return 0;
}
//小车右转
int move_right(geometry_msgs::TransformStamped &odom_trans)
{

	float theta;
	int i = 0;
	while (i < 2)
	{
		if (!atan(odom_trans.transform.translation.x / odom_trans.transform.translation.y)) theta = 0;//排除当x等于0时对theta的计算干扰
		else { theta = atan(odom_trans.transform.translation.x / odom_trans.transform.translation.y); }
		theta += 0.1;
		odom_trans.header.stamp = ros::Time::now();
		odom_trans.transform.translation.x += (velocity.y*sin(theta));					
		odom_trans.transform.translation.y += (velocity.y*cos(theta));
		odom_trans.transform.translation.z += velocity.z;
		position.x += (velocity.y*sin(theta));											//更新小车的位置信息
		position.y += (velocity.y*cos(theta));
		position.z += velocity.z;
		i++;
		odom_trans.transform.rotation = tf::createQuaternionMsgFromYaw(theta); //小车的角度设置
	}
	return 0;
}
//小车左转
int move_left(geometry_msgs::TransformStamped &odom_trans)
{

	float theta;
	int i = 0;
	while (i < 2)
	{
		if (!atan(odom_trans.transform.translation.x / odom_trans.transform.translation.y)) theta = 0;//排除当x等于0时对theta的计算干扰
		else { theta = atan(odom_trans.transform.translation.x / odom_trans.transform.translation.y); }
		theta -= 0.1;
		odom_trans.header.stamp = ros::Time::now();
		odom_trans.transform.translation.x += (velocity.y*sin(theta));
		odom_trans.transform.translation.y += (velocity.y*cos(theta));
		odom_trans.transform.translation.z += velocity.z;
		position.x += (velocity.y*sin(theta));											//更新小车的位置信息
		position.y += (velocity.y*cos(theta));
		position.z += velocity.z;
		i++;
		odom_trans.transform.rotation = tf::createQuaternionMsgFromYaw(theta); //小车的角度设置
	}
	return 0;
}
//添加噪声
int add_noise(geometry_msgs::TransformStamped &odom_trans)
{
	float sigma = velocity.x + velocity.y + velocity.z;
	double noise[3];
	random_device rd;
	mt19937 gen(rd());
	normal_distribution<double> normal(0, sigma);
	for (int i = 0; i < 3; i++)
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
//通过回调函数改变state的状态
void directionCallback(const little_car::direction_msg::ConstPtr&  msg)
{
	my_state = msg->state;
	ROS_INFO("State is %d",my_state);
}
int main(int argc, char** argv) {
	ros::init(argc, argv, "state_publisher");
	ros::NodeHandle n;
	ros::Publisher joint_pub = n.advertise<sensor_msgs::JointState>("joint_states", 1);
	ros::Publisher pos_pub = n.advertise<geometry_msgs::Point>("car_position", 1); //小车的位置消息发布
	velocity.x = 0.0;    //速度设置，修改该参数可改变小车不同方向的速度
	velocity.y = 0.005;
	velocity.z = 0.0;
	/*
	 *请添加一个Subscriber，从你自己编写的Publisher处订阅指令
	 */

	ros::MultiThreadedSpinner spinner(4); 
	ros::Subscriber direction_info_sub = n.subscribe("/little_car/cmd", 100, directionCallback);
	spinner.spin();
	 /*
	  *若有需要，也可以从小车处发布你所需要的信息
	  */
	tf::TransformBroadcaster broadcaster;
	ros::Rate loop_rate(30);
	// message declarations
	geometry_msgs::TransformStamped odom_trans;
	sensor_msgs::JointState joint_state;
	odom_trans.header.frame_id = "odom";
	odom_trans.child_frame_id = "base_link";

	if (ros::ok()) {
		/***********不重要的部分*********************/
		joint_state.header.stamp = ros::Time::now();
		joint_state.name.resize(4);
		joint_state.position.resize(4);
		joint_state.name[0] = "base_to_wheel_1";
		joint_state.position[0] = 0;
		joint_state.name[1] = "base_to_wheel_2";
		joint_state.position[1] = 0;
		joint_state.name[2] = "base_to_wheel_3";
		joint_state.position[2] = 0;
		joint_state.name[3] = "base_to_wheel_4";
		joint_state.position[3] = 0;
		/********************************************/

		//判断subscribe信息执行不同方向指令
		if (my_state == 0)
		{
			move_stop(odom_trans);
		}
		else if (my_state == 1)
		{
			move_forward(odom_trans);
		}
		else if (my_state == 2)
		{
			move_left(odom_trans);
		}
		else if (my_state == 3)
		{
			move_right(odom_trans);
		}
		else
		{
			ROS_INFO("Subcribe direction Info: Wrong state");
			move_forward(odom_trans);
		}
		
		pos_pub.publish(position);
		joint_pub.publish(joint_state);
		//add_noise(odom_trans);
		broadcaster.sendTransform(odom_trans);
		loop_rate.sleep();
	}


	return 0;
}


