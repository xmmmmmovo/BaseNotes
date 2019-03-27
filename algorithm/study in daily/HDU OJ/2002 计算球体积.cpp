/**
 * author: xmmmmmovo
 * generation time: 2019/03/26
 * filename: 2002 计算球体积.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define PI 3.1415927

using namespace std;

int main(int argc, char const *argv[]) {
    double r = 0;
    while (~scanf("%lf", &r)) {
        printf("%.3lf\n", (4.0/3.0)*PI*r*r*r);
    }

    // system("pause");
    return 0;
}