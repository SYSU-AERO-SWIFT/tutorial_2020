## 基础考核 - 第三周（10.11-10.18）

**ROS的基本使用**
 
1. 完成publisher，subscriber的topic通信
2. 完成client，server的service通信
3. 完成使用param_config文件进行设置的参数服务器
4. 使用roslaunch来启动节点

**测试方法**
1. 使用roslaunch启动topic通信

```shell
$ cd ros_project  # 请先确保工程在catkin workspace下
$ catkin_make  
$ source devel/setup.bash
$ roslaunch ramdom ramdom_topic.launch
```
2. 使用roslaunch启动service通信
$ roslaunch ramdom ramdom_service.launch

3. 使用roslauch启动param服务
$ roslaunch ramdom ramdom_param.launch

**文件位置**
1. 源代码在/src文件中
2. msg，srv，cfg分别放置了自定义的mssiage，service，param

