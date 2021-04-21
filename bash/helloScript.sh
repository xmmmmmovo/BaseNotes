#! /bin/bash

echo "hello bash script!" > file.txt


: '
注释
'

# 输入
# cat > file.txt

cat << k
this is a text
aaaaaaaa
k

