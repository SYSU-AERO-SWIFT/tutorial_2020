# topic和service通信任务
** 作者 **：陈睿    
** 修订 **：陈睿    
** 日期 **：2020-10-18            
** 版本 **：1.0.0      
** 摘要 **：这里是topic和service通信任务的完成情况报告     

## topic通信
源文件存在`catkind ws`工作空间的`topic pkg`中，信息发布节点可以发布自定义的信息类型，订阅节点会将收到的随机数字输出到终端；可以通过launch文件启动两个节点     

** 调试 **     
> catkin_make #要位于工作空间catkin_make下    
> source devel/setup.bash    
> roslaunch topic_pkg number.launch   

## service通信   
源文件存在`catkind_ws`工作空间的`service_pkg`中,Client 可以产生一个 0 到 1 内的随机浮点数，并发给 Service，Service 接受到请求后可以判断随机数是否小于 0.5，若是则回应布尔值 1，否则回应 0。Client 接收到回应后，先输出产生的随机数，然后输出 Yes 或 No 到终端。同时编写了一个参数服务器，可以调整用于判断的浮点数0.5，范围为0到1

** 调试 **   
>#转到工作空间下    
>$catkin_make    
>$source devel/setup.bash    
>$roslaunch service_pkg range.launch     
>#启动参数服务器，要在工作空间catkin_ws下重开一个终端   
>$source devel/setup.bash    
>$rosrun rqt_reconfigure rqt_reconfigure    


