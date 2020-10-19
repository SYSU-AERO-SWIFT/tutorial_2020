#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

struct move_robot{

	public:
	move_robot(int n);

	visualization_msgs::Marker head;
	visualization_msgs::Marker body;
	visualization_msgs::Marker hand;
	float pos_x,pos_y;
	int ori;//0-7对应0，45，90，135，180，225，270，315，180，
	int n;
	void move();
	void pos_go(int t);
	private:
	//大小
	const float head_scalex=0.4,head_scaley=0.4,head_scalez=0.4;
	const float body_scalex=0.2,body_scaley=0.2,body_scalez=1.0;
	const float hand_scalex=0.2,hand_scaley=0.8,hand_scalez=0.2;
	//组合位置
	const float head_posx=0.0,head_posy=0.0,head_posz=1.2;
	const float body_posx=0.0,body_posy=0.0,body_posz=0.5;
	const float hand_posx=0.0,hand_posy=0.0,hand_posz=0.60;
	//姿态
	
		
	
};

move_robot::move_robot(int n){
	this->n=n;
	head.header.frame_id = "/my_frame";
	body.header.frame_id = "/my_frame";
	hand.header.frame_id = "/my_frame";
	head.ns = "head";
    head.id = n;
	body.ns = "body";
    body.id = n;
	hand.ns = "hand";
    hand.id = n;
	//形状
	head.type = visualization_msgs::Marker::SPHERE;
	body.type = visualization_msgs::Marker::CUBE;
	hand.type = visualization_msgs::Marker::CUBE;
	//动作
	head.action = visualization_msgs::Marker::ADD;
	body.action = visualization_msgs::Marker::ADD;
	hand.action = visualization_msgs::Marker::ADD;
	//大小
	head.scale.x = head_scalex;
    	head.scale.y = head_scaley;
    	head.scale.z = head_scalez;
	body.scale.x = body_scalex;
    	body.scale.y = body_scaley;
    	body.scale.z = body_scalez;
	hand.scale.x = hand_scalex;
    	hand.scale.y = hand_scaley;
    	hand.scale.z = hand_scalez;
	//颜色
	head.color.r = 1.0f;
	head.color.g = 0.0f;
	head.color.b = 0.0f;
	head.color.a = 1.0;
	body.color.r = 0.0f;
	body.color.g = 1.0f;
	body.color.b = 0.0f;
	body.color.a = 1.0;
	hand.color.r = 0.0f;
	hand.color.g = 0.0f;
	hand.color.b = 1.0f;
	hand.color.a = 1.0;	

	
	
	pos_x=rand()%12000/1000-6.00;
	pos_y=rand()%12000/1000-6.00;
	
	ori=rand()%8;	
}
void move_robot::move(){
	//更新时间戳
	head.header.stamp = ros::Time::now();
	body.header.stamp = ros::Time::now();
	hand.header.stamp = ros::Time::now();
	//更新方向角度	
	if(ori==0||ori==4){
	hand.pose.orientation.w = 1;
	hand.pose.orientation.x = 0;
	hand.pose.orientation.y = 0;
	hand.pose.orientation.z = 0;
	}
	else if(ori==1||ori==5){
	hand.pose.orientation.w = sqrt(2+sqrt(2))/2;
	hand.pose.orientation.x = 0;
	hand.pose.orientation.y = 0;
	hand.pose.orientation.z = -sqrt(2)/(4*sqrt(2+sqrt(2))/2);
	}
	else if(ori==2||ori==6){
	hand.pose.orientation.w = sqrt(2-sqrt(2))/2;
	hand.pose.orientation.x = 0;
	hand.pose.orientation.y = 0;
	hand.pose.orientation.z = -sqrt(2)/(4*sqrt(2-sqrt(2))/2);
	}
	else if(ori==3||ori==7){
	hand.pose.orientation.w = sqrt(2-sqrt(2))/2;
	hand.pose.orientation.x = 0;
	hand.pose.orientation.y = 0;
	hand.pose.orientation.z = sqrt(2)/(4*sqrt(2-sqrt(2))/2);
	}
	else {
		ori%=8;
	}
	//更新位置
	head.pose.position.x = pos_x+head_posx;
    	head.pose.position.y = pos_y+head_posy;
    	head.pose.position.z = head_posz;
	body.pose.position.x = pos_x+body_posx;
    	body.pose.position.y = pos_y+body_posy;
    	body.pose.position.z = body_posz;
	hand.pose.position.x = pos_x+hand_posx;
    	hand.pose.position.y = pos_y+hand_posy;
    	hand.pose.position.z = hand_posz;

	
	head.lifetime = ros::Duration();
	body.lifetime = ros::Duration();
	hand.lifetime = ros::Duration();
}//姿态控制

//位置移动
void move_robot::pos_go(int t){
		double noise[2];
		noise[0] = rand()%100/800; //噪声
		noise[2] = rand()%100/800;
        	pos_x += noise[0];			
        	pos_y += noise[1];
		
		if(ori==0){
			pos_x+=0.03;
		}
		else if(ori==1){
			pos_x+=0.03/sqrt(2);
			pos_y+=0.03/sqrt(2);
		}
		else if(ori==2){
			pos_y+=0.03;
		}
		else if(ori==3){
			pos_y+=0.03/sqrt(2);
			pos_x-=0.03/sqrt(2);
		}	
		else if(ori==4){
			pos_x-=0.03;
		}
		else if(ori==5){
			pos_x-=0.03/sqrt(2);
			pos_y-=0.03/sqrt(2);
		}
		else if(ori==6){
			pos_y-=0.03;
		}
		else if(ori==7){
			pos_y-=0.03/sqrt(2);
			pos_x+=0.03/sqrt(2);
		}	
		else{
		ori%=8;		
		}
		
		if((t%(8+n))==0)ori+=2;	

}//加噪声

int main( int argc, char** argv )
{
  ros::init(argc, argv, "move_robot");
  ros::NodeHandle n;
  ros::Rate r(10);
  srand((int)time(0));  // 产生随机种子
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 40);
	int t=0;
	move_robot m1(1);
	move_robot m2(2);
	move_robot m3(3);
	move_robot m4(4);
	move_robot m5(5);
	move_robot m6(6);
	move_robot m7(7);
	move_robot m8(8);
	move_robot m9(9);
	move_robot m10(10);
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
    
    m1.pos_go(t);m2.pos_go(t);m3.pos_go(t);m4.pos_go(t);m5.pos_go(t);m6.pos_go(t);m7.pos_go(t);m8.pos_go(t);m9.pos_go(t);m10.pos_go(t);
    m1.move();m2.move();m3.move();m4.move();m5.move();m6.move();m7.move();m8.move();m9.move();m10.move();
    
    marker_pub.publish(m1.head);marker_pub.publish(m1.body);marker_pub.publish(m1.hand);

    marker_pub.publish(m2.head);marker_pub.publish(m2.body);marker_pub.publish(m2.hand);
    marker_pub.publish(m3.head);marker_pub.publish(m3.body);marker_pub.publish(m3.hand);
    marker_pub.publish(m4.head);marker_pub.publish(m4.body);marker_pub.publish(m4.hand);
    marker_pub.publish(m5.head);marker_pub.publish(m5.body);marker_pub.publish(m5.hand);
    marker_pub.publish(m6.head);marker_pub.publish(m6.body);marker_pub.publish(m6.hand);
    marker_pub.publish(m7.head);marker_pub.publish(m7.body);marker_pub.publish(m7.hand);
    marker_pub.publish(m8.head);marker_pub.publish(m8.body);marker_pub.publish(m8.hand);
    marker_pub.publish(m9.head);marker_pub.publish(m9.body);marker_pub.publish(m9.hand);
    marker_pub.publish(m10.head);marker_pub.publish(m10.body);marker_pub.publish(m10.hand);
    
    t++;
    r.sleep();
  }
}
