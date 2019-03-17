/**
 * author: xmmmmmovo
 * generation time: 2019/03/17
 * filename: student.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include "student.h"

Student::Student()
{
    num = 0;
    name = "NULL";
    sex = 'M';
}

void Student::set_value(int num, string name, char sex){
    this->num = num;
    this->name = name;
    this->sex = sex;
}