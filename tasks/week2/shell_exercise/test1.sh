#!/bin/bash
mkdir -v /tmp/scripts
cd /tmp/scripts
cp /etc/pam.d ./test
chown -R redhat ./test
chmod -R o=--- ./test
