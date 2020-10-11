#!/bin/bash


# 创建目录
mkdir /tmp/scripts

cd /tmp/scripts

# 复制目录
cp -r  /etc/pam.d ./

# 改名
mv ./pam.d ./test

# 改变所有者
chown -R redhat test

#改变其他人的权限
chmod -R o=--- test




