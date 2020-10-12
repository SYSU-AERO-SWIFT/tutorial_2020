#!/bin/bash

#写一个脚本
#       1.显示当前系统日期和时间，而后创建目录/tmp/lstest
#       2.切换工作目录至/tmp/lstest
#       3.创建目录a1d，b56e，6test
#       4.创建空文件xy，x2y，732
#       5.列出当前目录下以a，x或者6开头的文件或目录
#       6.列出当前目录下以字母开头，后跟一个任意数字，而后跟任意长度字符的文件或目录

FOLDER=/tmp/lstest

date   #显示当前时间与日期
if [ ! -d ${FOLDER} ]  #判断目录是否存在，如果不存在则创建
then
	mkdir ${FOLDER}
fi

cd ${FOLDER}

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

ls [ax6]*
ls [[:alpha:]][[:digit:]]*   
