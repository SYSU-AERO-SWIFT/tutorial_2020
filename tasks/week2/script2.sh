#!/bin/bash
#显示当前系统日期和时间，而后创建目录 /tmp/lstest。
#切换工作目录至 /tmp/lstest。
#创建目录 a1d，b56e，6test。
#创建空文件 xy，x2y，732。
#列出当前目录下以 a，x 或者 6 开头的文件或目录。
#列出当前目录下以字母开头，后跟一个任意数字，而后跟任意长度字符的文件或目录。


mulu=/tmp/lstest
date

mkdir ${mulu}    #创建目录
cd ${mulu}

if [ ! -d "a1d" ]
then
	mkdir a1d
fi

if [ ! -d "b56e" ]
then
	mkdir b56e
fi

if [ ! -d "6test" ]
then
	mkdir 6test
fi

if [ ! -f "xy" ]
then
	touch xy
fi

if [ ! -f "x2y" ]
then
	touch x2y
fi

if [ ! -f "732" ]
then
	touch 732
fi

ls [6ax]*
ls [[:alpha:]][[:digit:]]* 
