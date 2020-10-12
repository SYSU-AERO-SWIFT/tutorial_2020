#!/bin/bash
#写一个脚本：
#       1.创建目录/tmp/scripts
#       2.切换工作目录至此目录中
#       3.复制/etc/pam.d目录至当前目录，并重命名为test
#       4.将当前目录的test及其里面的文件和子目录的属主改为gino
#       5.将test及其子目录中的文件的其它用户的权限改为没有任何权限
FOLDER=/tmp/scripts 
FOLDER_SOURCE=/etc/pam.d 

if [ ! -d ${FOLDER} ]#判断目录是否存在，不存在则创建目录 
then 
	mkdir $FOLDER 
fi 

cd ${FOLDER} #切换到工作目录 
cp -rf $FOLDER_SOURCE ./test 
chown -R sunny ./test #更改属主 
chmod 700 ./test #更改权限

