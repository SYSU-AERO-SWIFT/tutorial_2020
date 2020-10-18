#include<ros/ros.h>
#include<iostream>
#include<service_pkg/number.h>
using namespace std;
int main(int argc,char**argv)
{
        ros::init(argc,argv,"client_node");
        ros::NodeHandle nh;
        ros::ServiceClient client=nh.serviceClient<service_pkg::number>("range_service");
        ros::Rate loop_rate(1.0);
        service_pkg::number srv;
        while(ros::ok())
        {
        srv.request.number=rand() / float(RAND_MAX);
        if(client.call(srv))
            {
                std::cout<<"产生的随机数为："<<srv.request.number<<std::endl;
                if(srv.response.feedback==1)std::cout<<"Yes"<<std::endl;
                if(srv.response.feedback==0)std::cout<<"No"<<std::endl;
            }
        loop_rate.sleep();
        }
return 0;
}

