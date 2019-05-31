/**
 * author: xmmmmmovo
 * generation time: 2019/05/28
 * filename: 2.cpp
 * language & build version : C++ 11
*/
/*
定义一个车(vehicle)基类，具有MaxSpeed、Weight等成员变量，Run、Stop等成员函数
，由此派生出自行车(bicycle)类、汽车(motorcar)类。自行车类有高度(height)等属性
，汽车类有座位数(SeatNum)等属性。从bicycle和motorcar派生出摩托车(motorcycle)类
，在继承过程中，注意把vehicle设置为虚基类。
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Vehicle
{
private:
    int m_MaxSpeed = 0;
    int m_Weight = 0;
public:
    Vehicle(int maxsp = 0, int wei = 0)
     : m_MaxSpeed(maxsp), m_Weight(wei) {}

    int get_max_speed() {
        return m_MaxSpeed;
    }
    int get_weight() {
        return m_Weight;
    }
};

class Bicycle : virtual public Vehicle
{
private:
    int m_Height;
public:
    Bicycle(int maxspeed, int weight, int height)
     : Vehicle(maxspeed, weight), m_Height(height) {}
    int get_height() {
        return m_Height;
    }
};

class MotorCar : virtual public Vehicle
{
private:
    int m_SetNum;
public:
    MotorCar(int maxspeed, int weight, int setnum)
     : Vehicle(maxspeed, weight), m_SetNum(setnum) {}
    int get_set_num() {
        return m_SetNum;
    }
};

class MotoCycle : public Bicycle, public MotorCar
{
private:
public:
    MotoCycle(int maxspeed, int weight, int setnum, int height)
     : MotorCar(maxspeed, weight, setnum)
     , Bicycle(maxspeed, weight, height)
     , Vehicle(maxspeed, weight) {}
};

int main(int argc, char const *argv[]) {
    MotoCycle m(12, 12, 12, 12);

    cout << m.get_max_speed() << endl;
    cout << m.get_weight() << endl;
    cout << m.get_set_num() << endl;
    cout << m.get_height() << endl;

    system("pause");
    return 0;
}