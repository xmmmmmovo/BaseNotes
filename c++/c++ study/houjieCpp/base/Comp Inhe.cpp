/**
 * author: xmmmmmovo
 * generation time: 2019/05/03
 * filename: Comp Inhe.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>

using namespace std;

class Base
{
private:
public:
    Base();
};

Base::Base()
{
    cout << "ji lei con" << endl;
}

class Component
{
private:
    
public:
    Component();
};

Component::Component()
{
    cout << "fu he con!" << endl;
}

class Derived
{
private:
    // static int a;
    Component c;
public:
    Component c1;
    Derived();
};

Derived::Derived()
{
    cout << "pai sheng con!" << endl;
}

int main(int argc, char const *argv[]) {
    Derived d;
    // cout << endl;

    system("pause");
    return 0;
}