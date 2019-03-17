/**
 * author: xmmmmmovo
 * generation time: 2019/03/17
 * filename: question1.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Time
{
private:
    int hour;
    int minute;
    int second;
public:
    Time();
    void set_time(int, int, int);
    void show_time();
};

Time::Time()
{
    hour = 0;
    minute = 0;
    second = 0;
}

// this指代对象本身
void Time::set_time(int hour, int minute, int second){
    this->hour = hour;
    this->minute = minute;
    this->second = second;
}

void Time::show_time(){
    cout << hour << " : " << minute << " : " << second << endl;
}

// 根据课本 在这里设置了全局变量
Time t;

int main(int argc, char const *argv[])
{
    t.set_time(11, 45, 14);
    t.show_time();

    // system("pause");
    return 0;
}
/**
 * 编译版本MinGW64 8.1
 * 输出结果
 * 11 : 45 : 14
*/