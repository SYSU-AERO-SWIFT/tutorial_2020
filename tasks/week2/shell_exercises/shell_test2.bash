#!/bin/bash
#author 郑皓文
#data 10/11/2020

echo `date`

# 创建目录

mkdir /tmp/lstest
cd /tmp/lstest

# 创建文件和目录
mkdir a1d b56e 6test

touch xy x2y 732

# 找出a或x或6开头的文件或目录
echo `find -maxdepth 1 -name "[ax6]*"`

# 找出以字母开头，跟一个数字后面跟任意长度字符的文件或目录
echo `find -maxdepth 1 -name "[A-Za-b][0-9]*"`



