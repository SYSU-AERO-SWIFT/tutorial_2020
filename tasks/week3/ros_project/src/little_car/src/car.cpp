#include<ros/ros.h>
#include <geometry_msgs/Point.h>

/**
 * 该例程将订阅/car_position话题，发布/car_speed话题，自定义消息类型geometry_msgs::Point
   本节点将会订阅小车的实施位置信息，按照目标S型走向，对比位置变化给定理想与噪声PID计算后的速度信息进行发布
   S型函数，x=2sin(t*pi/180);y=2-2cos（t*pi/360)
 */



int x;

geometry_msgs::Point pos;

#define p 3
#define pd 360
#define pi (2*acos(0.0))
#define wx x*pi/180.0
#define wy 3*sin(wx)


void personInfoCallback(const geometry_msgs::Point::ConstPtr& msg)
{
    // 打印接收到的消息
    ROS_INFO("control get pos,x:%f,y:%f", msg->x,msg->y);
    pos.x=msg->x;
    pos.y=msg->y;
}

int main(int argc, char **argv)
{
    // ROS节点初始化
    ros::init(argc, argv, "car_publisher");

    // 创建节点句柄
    ros::NodeHandle n;
    ros::Subscriber point_sub = n.subscribe("car_pos", 1, personInfoCallback);
    // 创建一个Publisher，发布名为/car_speed 的topic，消息类型geometry_msgs::Point，队列长度1
    ros::Publisher car_speed_pub = n.advertise<geometry_msgs::Point>("/car_speed", 1);
   
    // 设置循环的频率
    ros::Rate loop_rate(20);
    pos.x=0;   
    pos.y=0;
    pos.z=0;
    x=0;
    float xl=0,yl=0,vx0,vy0,vxl,vyl;//原速度和实际速度
    while (ros::ok())
    {	
	ros::spinOnce();  //订阅小车的控制信息
	geometry_msgs::Point speed_msg;
	if(x>720){
	speed_msg.x=0;	
	speed_msg.y=0;
	}
	else{
	vxl=speed_msg.x;
	vyl=speed_msg.y;
	vx0=pi/720.0+(xl-pos.x)/p;
	vy0=2*pi/360.0*cos(wx)/2+(yl-pos.y)/p;
	speed_msg.x=pi/360.0/2+(xl-pos.x)/p+(vxl-vx0)/pd;
 	speed_msg.y=2*pi/360.0*cos(wx)/2+(yl-pos.y)/p+(vyl-vy0)/pd;//修正并且采用微分环节增加平滑度
	xl=wx/2;
	yl=wy/2;
	}
       
	car_speed_pub.publish(speed_msg);
	
        // 按照循环频率延时
	x++;
	
        loop_rate.sleep();
	
	
    }

    return 0;
}


