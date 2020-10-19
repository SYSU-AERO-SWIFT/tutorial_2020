#include<ros/ros.h>
#include<ramdom_num/uni.h>


/**
 * 该例程将发布/ramdom_info话题，自定义消息类型ramdom_num::uni
 */


int main(int argc, char **argv)
{
    // ROS节点初始化
    ros::init(argc, argv, "uni_publisher");

    // 创建节点句柄
    ros::NodeHandle n;

    // 创建一个Publisher，发布名为/ramdom_info的topic，消息类型ramdom_num::uni，队列长度10
    ros::Publisher uni_info_pub = n.advertise<ramdom_num::uni>("/ramdom_info", 10);

    // 设置循环的频率
    ros::Rate loop_rate(1);
	
    srand((int)time(0));  // 产生随机种子
    while (ros::ok())
    {
        // 初始化learning_topic::Person类型的消息
    	ramdom_num::uni uni_msg;
		uni_msg.intu = rand()%10000;

        // 发布消息
		uni_info_pub.publish(uni_msg);

       	ROS_INFO("Publish uniform Info: num:%d", 
				  uni_msg.intu);

        // 按照循环频率延时
        loop_rate.sleep();
    }

    return 0;
}
