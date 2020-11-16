#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<thread>      //创建线程
#include<mutex>       //互斥锁
#include<unistd.h>    //Sleep()
#include<condition_variable>
using namespace std;
void reader_func(int index, int thread_r, int arrive, int spend);
void writer_func(int index2, int thread_w, int arrive, int spend);


