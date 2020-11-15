# 读者写者项目
**作者**:陈睿   
**修订**:陈睿   
**日期**:2020-11-15   
**版本**:v1.0.4   
**摘要**:这是有关读者写者项目的介绍，包含项目所含的文件、解题思路、运行方法
# 包含的文件   
`bin`：存放可运行文件   
`build`：存放.o文件   
`include`：存放头文件   
`src`：存放源文件   
`TEST_FILES`：存放用于测试的文件   
`Makefile`   
`README.md`   
# 解题思路
**时间**:   
设置了一个全局变量time_now=0，相当于标准时间，每挂起1s则time_now加1，依据这个标准时间发出线程   
**写者互斥**:   
设置了一个互斥锁，并利用了condition_variable_any变量condar，使得写者间能通过到来的顺序依次唤醒   
**读写互斥**:   
当有写者在前时，读者利用condition_variable_any变量cv来等待（wait），在其之前的最后一个writer进行唤醒;而读者间通过前一个读者进行依次唤醒   
# 运行方法-项目文件下打开终端
编译：
>$make    
>g++ -c src/main.cpp -o build/main.o -I include  -std=c++11   
>g++ -c src/thread.cpp -o build/thread.o -I include -std=c++11    
>g++ build/main.o build/thread.o -o bin/wr.out -pthread -std=c++11    

运行：   
>$ ./bin/wr.out ./TEST_FILES/<测试文件名>   
