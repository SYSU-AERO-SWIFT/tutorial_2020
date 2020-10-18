# 小车任务
**作者**：陈睿    
**修订**：陈睿    
**日期**：2020-10-18            
**版本**：1.0.0      
**摘要**：这里是小车任务的完成情况报告     

## 完成情况
在ros_project_me工作空间下，可以通过自定义的publisher向小车发布自定义的消息，小车接受到消息后，可以在噪声下走出S形弯；未完成多线程任务   

**调试**   
位于工作空间ros_project下    
>$catkin_make     
>$source devel/setup.bash    
>$roslaunch launch/little_car.launch #此时只显示出车体，要运动需要
启动自定义的publisher发布行走S的消息   

启动publisher_node，要回到工作空间，新开一个终端   
>$source devel/setup.bash   
>$rosrun turning_pkg publishers    


