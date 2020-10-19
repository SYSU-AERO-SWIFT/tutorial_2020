## Server & Client

- 编写者：陈博洋
- 日期：2020-10-18
- 版本：v3.0.0
- 梗概：使用 ROS 编写两个节点（C++），实现从客户端向服务器收发随机数据；实现动态参数服务器

### 包
    random_float

### 可执行文件
    judge_client // Client
    judge_server // Server & Dynamic

### 调试
    $ pwd // 确保在 catkin_ws_2 目录下
    $ source ./devel/setup.bash // 运行启动脚本，设置配置
    $ catkin_make // 编译
    $ roscore // 运行 roscore

    // 打开一个新的 shell
    $ cd {your_dir}/catkin_ws_2
    $ source ./devel/setup.bash
    $ rosrun random_float judge_server

    // 打开一个新的 shell
    $ cd {your_dir}/catkin_ws_2
    $ source ./devel/setup.bash
    $ rosrun random_float judge_client

    // 打开一个新的 shell
    $ rosrun rqt_console rqt_console // 运行 rqt_console

### 问题
- 运行 GUI 程序时找不到 libQt5Core.so.5 文件，但该文件实际存在搜索路径的目录中，尝试过网上的各种解决办法都没有用
- 第一次使用 catkin_make 时没有问题，但第二次使用 catkin_make 编译时提示动态参数服务器的回调函数在作用域内未声明，未找到解决办法