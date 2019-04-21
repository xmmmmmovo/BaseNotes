/**
 * author: xmmmmmovo
 * generation time: 2019/03/17
 * filename: test.cpp
 * language & build version : C++ 11
*/
#include <cstdio>
#include <cmath>
#include <iostream>

int getNumber() {
    static int a = 0;
    return a++;
}

int main(int argc, char **argv)
{
    int t = 5;

    while (t--) {
        getNumber();
    }
    
    std::cout << getNumber() << t << std::endl;

    system("pause");
    return 0;
}
