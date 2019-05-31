/**
 * author: xmmmmmovo
 * generation time: 2019/05/28
 * filename: 2.cpp
 * language & build version : C++ 11
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

    virtual void run() = 0;
    virtual void stop() = 0;
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

    void run() {
        cout << "Bicycle runing" << endl;
    }
    void stop() {
        cout << "Bicycle stop" << endl;
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

    void run() {
        cout << "MotorCar runing" << endl;
    }
    void stop() {
        cout << "MotorCar stop" << endl;
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

    void run() {
        cout << "MotoCycle runing" << endl;
    }
    void stop() {
        cout << "MotoCycle stop" << endl;
    }
};

int main(int argc, char const *argv[]) {
    MotoCycle m(12, 12, 12, 12);

    m.run();
    m.stop();

    system("pause");
    return 0;
}