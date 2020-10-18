#include <urdf/model.h>
#include <string>
#include <sensor_msgs/JointState.h>
#include <tf/transform_broadcaster.h>
#include <geometry_msgs/Point.h>
#include <ros/ros.h>
#include <random>
#include <iomanip>
geometry_msgs::Point position; //小车的位置信息
geometry_msgs::Point pos; //小车的位置信息
geometry_msgs::Point velocity; //小车的速度控制
using namespace std;
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
		pos.x += position.x;											//更新小车的位置信息
		pos.y += position.y;
		pos.z += position.z;
        odom_trans.transform.rotation = tf::createQuaternionMsgFromYaw(0.0-atan(velocity.x/velocity.y)); //小车的角度设置
		return 0;
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

// 接收到订阅的消息后，会进入消息回调函数
void personInfoCallback(const geometry_msgs::Point::ConstPtr& msg)
{
    	velocity.x=msg->x;    //速度设置，修改该参数可改变小车不同方向的速度
	velocity.y=msg->y;
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "state_publisher");
    ros::NodeHandle n;
    ros::Publisher joint_pub = n.advertise<sensor_msgs::JointState>("joint_states", 1);
	ros::Publisher pos_pub = n.advertise<geometry_msgs::Point>("car_position",1); //小车的位置消息发布
	
	  // 创建一个Subscriber，订阅名为/car_speed的topic，注册回调函数personInfoCallback
    ros::Subscriber car_speed_sub = n.subscribe("/car_speed", 1, personInfoCallback);
    ros::Publisher car_pos_pub = n.advertise<geometry_msgs::Point>("car_pos",1); //小车的位置消息发布
	
    tf::TransformBroadcaster broadcaster;
    ros::Rate loop_rate(20);
    // message declarations
    geometry_msgs::TransformStamped odom_trans;
    sensor_msgs::JointState joint_state;
    odom_trans.header.frame_id = "odom";
    odom_trans.child_frame_id = "base_link";
	velocity.x=-0.0;    //速度设置，修改该参数可改变小车不同方向的速度
	velocity.y=0.0;
	velocity.z=0.0;
    while (ros::ok()) {
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
		
		//此处调用move_forward函数，使小车一直匀速前进
		move_forward(odom_trans);
		car_pos_pub.publish(position);
		pos_pub.publish(position);
        joint_pub.publish(joint_state);
		add_noise(odom_trans);
        broadcaster.sendTransform(odom_trans);
	
	ros::spinOnce();
        loop_rate.sleep();		
    }


    return 0;
}


