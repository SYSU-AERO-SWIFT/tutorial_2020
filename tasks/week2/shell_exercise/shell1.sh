#!/bin/bash

#写一个脚本
#创建目录 /tmp/scripts。
#切换工作目录至此目录中。
#复制 /etc/pam.d 目录至当前目录，并重命名为 test。
#将当前目录的 test 及其里面的文件和子目录的属主改为 redhat。
#将 test 及其子目录中的文件的其它用户的权限改为没有任何权限。

mulu=/tmp/scripts
copymulu=/etc/pam.d

if [ ! -d /tmp ]
then
	mkdir /tmp/scripts
fi

cd tmp/scripts          #切换目录
cp -rf /etc/pam.d ./test       
echo "hello"
chown -R muyin ./test    #更改所属主
chmod 700 ./test           #更改权限
