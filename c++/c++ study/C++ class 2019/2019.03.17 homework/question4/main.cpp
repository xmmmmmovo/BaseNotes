/**
 * author: xmmmmmovo
 * generation time: 2019/03/17
 * filename: main.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "student.h" // 把头文件包含进来便包含了Student类

using namespace std;

int main(int argc, char const *argv[])
{
    Student stu;
    stu.display();
    stu.set_value(114514, "田所浩二", 'M');
    stu.display();

    system("pause");
    return 0;
}