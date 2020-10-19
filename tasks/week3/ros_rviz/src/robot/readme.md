## 基础考核 - 第三周（10.11-10.18）

**任务9模拟器**

**实现内容**
1. 障碍机器人，移动机器人的仿真（平均噪声）
2. 无人机仿真（未包括传感器）
3. 在rviz上面显示出来

**文件位置**
> robot/src/
>> frame.cpp --发布场地信息
>> maker1.cpp -- 障碍机器人1
>> maker2.cpp -- 障碍机器人2
>> maker3.cpp -- 障碍机器人3
>> maker4.cpp -- 障碍机器人4
>> sim_robot.cpp -- 10个移动机器人
>> plane.cpp -- 无人机

**运行方法**

```shell1
$ cd ros_rviz  # 请先确保工程在catkin workspace下
$ catkin_make  
$ source devel/setup.bash
$ roslaunch robot robot.launch
```
```shell2
$ rviz
```
在rviz中把frame设置为my_frame
然后add by topic 中的visualization_marker话题下的Marker.即可看到模拟内容。
