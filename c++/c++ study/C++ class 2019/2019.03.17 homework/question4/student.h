/**
 * author: xmmmmmovo
 * generation time: 2019/03/17
 * filename: student.h
 * language & build version : C++ 11
*/
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    int num;
    string name;
    char sex;
public:
    Student();
    inline void display();
    void set_value(int, string, char);
};

/**
 * inline 函数必须写道头文件当中
*/
void Student::display(){
    cout << "num: " << num << endl;
    cout << "name: " << name << endl;
    cout << "sex: " << sex << endl;
}


#endif // STUDENT_H