# 编程技术方向

**只供大一同学选择**

## 第一部分：读者写者问题

### 具体要求

- 现在有两种人, 一种是写者 `writer`, 另一种是读者 `reader`, 他们都想使用洗衣机, writer 互相之间非常讨厌对方, 而且人高马大.
- 我们规定同一时间内只能有一个 writer 或者多个 reader 来用洗衣机, 其余人必须进行等待, 也就是说 reader 之间可以同时用洗衣机 (就像宿舍里有时会一起洗衣服), writer 之间不能同时用洗衣机, writer 与 reader 之间不能同时用洗衣机.
- 在其余人等待期间, 如果有 writer 到来, 那么它仗着自己人高马大, 所以它会插队并排到所有的 reader 之前, 所有的 writer 之后, 也就是说 writer 比 reader 在等待期间具有更高的优先级.
- 如果目前洗衣机里面的衣服是 reader 的, 并且在此期间队列头部为 reader, 那么他可以直接把衣服丢到洗衣机里面, 而不用等待.
- 只要目前有人在等待, 那么洗衣机当前衣物洗完后, 马上就能用下一次.
- 必须使用多线程.

- 程序开始后 writer 与 reader 分别会在不同的时间内到来, 由一个 txt 文件指出, 比如

`test_1.txt`
```txt
1 R 3 5  
2 W 4 5  
3 R 5 2  
4 R 6 5  
5 W 7 3
```  

1. 第二、四、六列为空格
2. 第三列表示 writer(W) 或者 reader(R).
3. 第五列表示在第几秒到来 (按照上述规则, 进行等待或者用洗衣机)
4. 第七列表示从开始用洗衣机到结束需要几秒 (每个人使用时间可能不同)

比如第一行表示有一个 reader 会在程序开始 3s 后到来, 用洗衣机持续时间为 5s

### 输出要求

- 在 `main()` 内的所有输出要求开头为 `[main]`
- 当前线程开始使用洗衣机时要求输出, 结束使用洗衣机时要求输出, 具体格式如下
  - 开始使用洗衣机: `[相关线程名称] + 此时时间 + "Keep for" + 持续使用洗衣机的时间`
  - 结束使用洗衣机: `[相关线程名称] + 此时时间 + exit`。

例子:

```shell
[main] start
[main] try open test_1.txt
[main] open test_1.txt success
[reader1] 3s: Keep for 5s
[reader1] 8s: exit
[writer1] 8s: Keep for 5s
[writer1] 13s: exit
[writer2] 13s: Keep for 3s
[writer2] 16s: exit
[reader2] 16s: Keep for 2s
[reader3] 16s: Keep for 5s
[reader2] 18s: exit
[reader3] 21s: exit
```

### 工程结构要求

- `src/` 存放 `.cpp` 源码
- `include/` 存放头文件
- `bin/` 存放可执行文件
- `TEST_FILES/` 存放相应的测试文件
- 要求编写 `README`, 在其中注明运行方法以及运行结果截图
- 编写相应的 `Makefile` 或 `CMakeLists.txt`

比如:

```shell
--./
    bin/
    build/
    src/
    include/
    TEST_FILES/
    README.md
    Makefile
```

### 具体测试文件

| 文件 |
|:---:|
|`test_1.txt`|
|`test_2.txt`|
|`test_3.txt`|
|`test_4.txt`|
|`test_5.txt`|

### 评分规则

- **满分300分**  

| **加分项** | **扣分项** |
|:---:|:---:|
| Makefile 编译通过 + 50分| Makefile编译不通过则项目整体为 0 分|
| 每通过一个 txt 文件 + 50分| 未按照相应的输出要求输出但结果正确, 每个 txt -2 分|
| 未通过则不加分| 工程结构未按照要求 -50 分|
| 使用了多线程, 但线程顺序不正确, 正确的每个 txt 文件 +20 分| README 未按照上述要求写 -30分|

### 相关

- 语言限制: C / C++
- 环境: Linux (推荐 Ubuntu)
- 学习 C++ 多线程编程, 互斥锁

#### 参考

[1] [cppreference](https://en.cppreference.com)  
[2] [thread 线程库](https://en.cppreference.com/w/cpp/thread)  
[3] [互斥锁 mutex](https://en.cppreference.com/w/cpp/thread/mutex)  
[4] [sleep()](https://blog.csdn.net/qq_31828515/article/details/51615210)  
[5] [pthread](https://blog.csdn.net/u013894427/article/details/83827173)

#### 注意

- `pthread` 线程库与 `thread` 线程库任选其一即可
- 在 Linux 下编程如果使用了 `pthread` 库, 请在 `g++` 或者 `clang` 编译选项后面加上 `-lpthread`, 比如 `g++ main.cpp -lpthread` 或者 `clang main.cpp -lpthread`
- 如果使用 `thread` 库而出现编译错误, 请在编译选项后面加上 `-std=c++11`

## 第二部分：门电路设计

- 在高中的时候（甚至初中), 我们就已经简单的接触过电路知识, 也知道了与、或、非、异或等一些基础门电路知识。这一次, 我们就来简单的实现一个命令行版的门电路实验程序. 
- 了解图的 BFS.

### 具体要求

- 实现与、非、或、异或门
- 要能完成基本的用户交互。比如指定哪两个门连接, 等等
- 连接完成后, 可以给定输入来获取输出
- 能够正确的连接, 从而组成复杂组件, 提交时请提供设计的用于测试的输入（比如连接成一个全加器或其他）
- 必须使用类, 可以使用继承
- 在 README 中用自己的话概括 BFS 算法的过程

### 工程结构要求

- `src/` 存放 `.cpp` 源码
- `include/` 存放头文件
- `bin/` 存放可执行文件
- 要求编写 README, 在其中注明运行方法以及运行结果截图
- 编写相应的 Makefile 或 `CMakeLists.txt`

比如:

```shell
--./
    bin/
    build/
    src/
    include/
    README.md
    Makefile
```

### 评分规则

- **满分150分**
- 必须使用 C 或 C++
- Linux 下实现

| **加分项** | **扣分项** |
|:---:|:---:|
| Makefile 编译通过 + 50分| Makefile 编译不通过则项目整体为 0 分|
| 每一个门 +20 分| 自己没有指定测试输入则项目整体为 0 分|
| README 中有相关 BFS 的阐述 (禁止复制博客) +20 分| 未使用 class -50 分|

### FAQ

**Q:** 我该用什么符号来代表不同的门？  
**A:** 自由发挥, 但是你需要在文档里说明。

**Q:** 我该怎么设计交互界面比较好？  
**A:** 你可以将自己作为用户来思考, 你要用什么操作来连接？建议至少提供 `create`、`connect`、`list`、`setInput`、`exec`、`print` 这几个交互功能。如果你有其他更好的选择也可以, 只要能够实现功能即可。

**Q:** 我该怎么检查是否有环？(检查环不做要求, 但要了解)  
**A:** 可以参考图的 BFS 或 DFS
