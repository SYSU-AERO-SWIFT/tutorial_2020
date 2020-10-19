#include <ros/ros.h>
#include <service_pkg/number.h>
#include <dynamic_reconfigure/server.h>
#include <service_pkg/dynamicConfig.h>
float limit=0.5;
bool handle_function(service_pkg::number::Request &req,service_pkg::number::Response & res)
{
        if(req.number<limit)res.feedback=true;
        else res.feedback=false;
        return true;
}

void dynamic_callback(service_pkg::dynamicConfig &config,uint32_t level)
{
    limit= config.limit;
}
int main(int argc,char**argv)
{
        ros::init(argc,argv,"server_node");
        ros::NodeHandle nh;
        ros::ServiceServer service=nh.advertiseService("range_service",handle_function);
    dynamic_reconfigure::Server<service_pkg::dynamicConfig> server;
    dynamic_reconfigure::Server<service_pkg::dynamicConfig>::CallbackType f;

    f = boost::bind(&dynamic_callback, _1,_2);
    server.setCallback(f);
        ros::spin();
return 0;
}

