#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

#define pi 3.1415926

struct move_plane{

	public:
	move_plane();

	visualization_msgs::Marker gunz;
	visualization_msgs::Marker body;
	visualization_msgs::Marker hand1;
	visualization_msgs::Marker hand2;
	float pos_x,pos_y,pos_z;
	int ori;//0-7对应0，45，90，135，180，225，270，315，180，
	void move();
	void pos_go(int t);
	private:
	//大小
	const float gunz_scalex=0.2,gunz_scaley=0.2,gunz_scalez=0.4;
	const float body_scalex=1.0,body_scaley=1.0,body_scalez=0.5;
	const float hand1_scalex=0.2,hand1_scaley=1.0,hand1_scalez=0.2;
	const float hand2_scalex=1.0,hand2_scaley=0.2,hand2_scalez=0.2;
	//组合位置
	const float gunz_posx=0.0,gunz_posy=0.0,gunz_posz=0.45;
	const float body_posx=0.0,body_posy=0.0,body_posz=0.25;
	const float hand1_posx=0.0,hand1_posy=0.0,hand1_posz=0.80;
	const float hand2_posx=0.0,hand2_posy=0.0,hand2_posz=0.80;
	//姿态
	
		
	
};

move_plane::move_plane(){
	gunz.header.frame_id = "/my_frame";
	body.header.frame_id = "/my_frame";
	hand1.header.frame_id = "/my_frame";
	hand2.header.frame_id = "/my_frame";
	gunz.ns = "gunz";
    gunz.id = 0;
	body.ns = "body_plane";
    body.id = 0;
	hand1.ns = "hand1";
    hand1.id = 0;
	hand2.ns = "hand2";
    hand2.id = 0;
	//形状
	gunz.type = visualization_msgs::Marker::CUBE;
	body.type = visualization_msgs::Marker::CUBE;
	hand1.type = visualization_msgs::Marker::CUBE;
	hand2.type = visualization_msgs::Marker::CUBE;
	//动作
	gunz.action = visualization_msgs::Marker::ADD;
	body.action = visualization_msgs::Marker::ADD;
	hand1.action = visualization_msgs::Marker::ADD;
	hand2.action = visualization_msgs::Marker::ADD;
	//大小
	gunz.scale.x = gunz_scalex;
    	gunz.scale.y = gunz_scaley;
    	gunz.scale.z = gunz_scalez;
	body.scale.x = body_scalex;
    	body.scale.y = body_scaley;
    	body.scale.z = body_scalez;
	hand1.scale.x = hand1_scalex;
    	hand1.scale.y = hand1_scaley;
    	hand1.scale.z = hand1_scalez;
	hand2.scale.x = hand2_scalex;
    	hand2.scale.y = hand2_scaley;
    	hand2.scale.z = hand2_scalez;
	//颜色
	gunz.color.r = 1.0f;
	gunz.color.g = 1.0f;
	gunz.color.b = 0.0f;
	gunz.color.a = 1.0;
	body.color.r = 0.0f;
	body.color.g = 1.0f;
	body.color.b = 0.0f;
	body.color.a = 1.0;
	hand1.color.r = 1.0f;
	hand1.color.g = 0.0f;
	hand1.color.b = 0.0f;
	hand1.color.a = 1.0;	
	hand2.color.r = 1.0f;
	hand2.color.g = 0.0f;
	hand2.color.b = 0.0f;
	hand2.color.a = 1.0;	

	
	
	pos_x=0;
	pos_y=0;
	pos_z=0;
	ori=0;	
}
void move_plane::move(){
	//更新时间戳
	gunz.header.stamp = ros::Time::now();
	body.header.stamp = ros::Time::now();
	hand1.header.stamp = ros::Time::now();
	hand2.header.stamp = ros::Time::now();
	//更新方向角度	
	if(ori==0||ori==4){
	hand1.pose.orientation.w = 1;
	hand1.pose.orientation.x = 0;
	hand1.pose.orientation.y = 0;
	hand1.pose.orientation.z = 0;
	hand2.pose.orientation.w = 1;
	hand2.pose.orientation.x = 0;
	hand2.pose.orientation.y = 0;
	hand2.pose.orientation.z = 0;
	}
	else if(ori==1||ori==5){
	hand1.pose.orientation.w = sqrt(2+sqrt(2))/2;
	hand1.pose.orientation.x = 0;
	hand1.pose.orientation.y = 0;
	hand1.pose.orientation.z = -sqrt(2)/(4*sqrt(2+sqrt(2))/2);
	hand2.pose.orientation.w = sqrt(2+sqrt(2))/2;
	hand2.pose.orientation.x = 0;
	hand2.pose.orientation.y = 0;
	hand2.pose.orientation.z = -sqrt(2)/(4*sqrt(2+sqrt(2))/2);
	}
	else if(ori==2||ori==6){
	hand1.pose.orientation.w = sqrt(2-sqrt(2))/2;
	hand1.pose.orientation.x = 0;
	hand1.pose.orientation.y = 0;
	hand1.pose.orientation.z = -sqrt(2)/(4*sqrt(2-sqrt(2))/2);
	hand2.pose.orientation.w = sqrt(2-sqrt(2))/2;
	hand2.pose.orientation.x = 0;
	hand2.pose.orientation.y = 0;
	hand2.pose.orientation.z = -sqrt(2)/(4*sqrt(2-sqrt(2))/2);
	}
	else if(ori==3||ori==7){
	hand1.pose.orientation.w = sqrt(2-sqrt(2))/2;
	hand1.pose.orientation.x = 0;
	hand1.pose.orientation.y = 0;
	hand1.pose.orientation.z = sqrt(2)/(4*sqrt(2-sqrt(2))/2);
	hand2.pose.orientation.w = sqrt(2-sqrt(2))/2;
	hand2.pose.orientation.x = 0;
	hand2.pose.orientation.y = 0;
	hand2.pose.orientation.z = sqrt(2)/(4*sqrt(2-sqrt(2))/2);
	}
	else {
		ori%=8;
	}
	//更新位置
	gunz.pose.position.x = pos_x+gunz_posx;
    	gunz.pose.position.y = pos_y+gunz_posy;
    	gunz.pose.position.z = pos_z+gunz_posz;
	body.pose.position.x = pos_x+body_posx;
    	body.pose.position.y = pos_y+body_posy;
    	body.pose.position.z = pos_z+body_posz;
	hand1.pose.position.x = pos_x+hand1_posx;
    	hand1.pose.position.y = pos_y+hand1_posy;
    	hand1.pose.position.z = pos_z+hand1_posz;
	hand2.pose.position.x = pos_x+hand2_posx;
    	hand2.pose.position.y = pos_y+hand2_posy;
    	hand2.pose.position.z = pos_z+hand2_posz;
	
	
	gunz.lifetime = ros::Duration();
	body.lifetime = ros::Duration();
	hand1.lifetime = ros::Duration();
	hand2.lifetime = ros::Duration();
}//姿态控制

//位置移动
void move_plane::pos_go(int t){
	if(t%3600<1440){
	pos_x=4*cos(pi*t/180)-4;
	pos_y=4*sin(pi*t/180);
	pos_z=t*t/500000;
	}
	else if(t%3600<2880||t%3600>1440){
	pos_x=4*sin(t*pi/180);
	pos_y=4-4*cos(t*pi/360);
	pos_z=1440*1440/500000;
	}
	else{
	pos_x=4-4*sin(t*pi/180);
	pos_y=4*cos(t*pi/360);
	pos_z-=1440*1440/500000/720;
	}
	
	ori++;

}//加噪声

int main( int argc, char** argv )
{
  ros::init(argc, argv, "move_robot");
  ros::NodeHandle n;
  ros::Rate r(50);
  srand((int)time(0));  // 产生随机种子
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 40);
	int t=0;
	move_plane m1;

  while (ros::ok())
  {
    	
		
    // Publish the marker
    while (marker_pub.getNumSubscribers() < 1)
    {
      if (!ros::ok())
      {
        return 0;
      }
      ROS_WARN_ONCE("Please create a subscriber to the marker");
      sleep(1);
    }
    
    m1.pos_go(t);
    m1.move();
    
    marker_pub.publish(m1.gunz);
    marker_pub.publish(m1.body);
    marker_pub.publish(m1.hand1);
    marker_pub.publish(m1.hand2);
    
    t++;
    r.sleep();
  }
}
