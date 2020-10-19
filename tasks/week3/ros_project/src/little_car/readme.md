## 基础考核 - 第三周（10.11-10.18）

**小车项目**
> 我的小车实现了以下内容：

1. 通过publisher给小车发布控制命令
2. 在噪声下让小车平稳走完S形

> 实现方法：
car_publisher内部设置了订阅者，能订阅小车实施发布的位置信息，然后按照理想的S型路线与小车位置对比，发布小车的速度命令，指导小车完成S型用法；

> 使用的接口： 
1. 获取小车位置
2. 控制小车速度
3. 设置噪声等级

**测试方法**

```shell
$ cd ros_project  # 请先确保工程在catkin workspace下
$ catkin_make  
$ source devel/setup.bash
$ roslaunch launch/little_car.launch
```

