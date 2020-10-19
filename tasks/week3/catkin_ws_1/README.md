## Publisher & Subscriber

- 编写者：陈博洋
- 日期：2020-10-18
- 版本：v3.0.0
- 梗概：使用 ROS 编写两个节点（C++），实现随机数据的收发；使用 rosluanch 同时运行两个节点

### 包
    random_int

### 可执行文件
    talker // Publisher
    listener // Subscriber

### 调试
    $ pwd // 确保在 catkin_ws_1 目录下
    $ source ./devel/setup.bash // 运行启动脚本，设置配置
    $ catkin_make // 编译
    $ roscore // 运行 roscore

    //打开一个新的 shell
    $ cd {your_dir}/catkin_ws_1
    $ source ./devel/setup.bash
    $ rosrun random_int talker

    //打开一个新的 shell
    $ cd {your_dir}/catkin_ws_1
    $ source ./devel/setup.bash
    $ rosrun random_int listener
    ...
    ^C // 在该 shell 界面关闭 listener
       // 在上一个 shell 界面输入 ^C 关闭 talker
       //关闭运行 talker 的 shell

    $ roslaunch random_int random_int.launch // 启动 rosluanch
    ...
    ^C // 退出
       // 在第一个 shell 输入 ^C 退出 roscore