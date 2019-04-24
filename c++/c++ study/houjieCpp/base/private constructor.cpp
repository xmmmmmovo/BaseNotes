/**
 * author: xmmmmmovo
 * generation time: 2019/04/24
 * filename: private constructor.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

/**
 * 在单例设计模式时候class构造函数设定为private
 * 并不是说构造函数不能设定为private
*/
class PrivateConstructor
{
private:
    PrivateConstructor();
public:
    static PrivateConstructor& getInstance();
};

PrivateConstructor::PrivateConstructor() {
}

PrivateConstructor& PrivateConstructor::getInstance() {
    static PrivateConstructor p;
    return p;
}

int main(int argc, char const *argv[]) {
    

    system("pause");
    return 0;
}