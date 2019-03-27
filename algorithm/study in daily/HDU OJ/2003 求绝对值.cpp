/**
 * author: xmmmmmovo
 * generation time: 2019/03/26
 * filename: 2003 求绝对值.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
    double num;
    while (~scanf("%lf", &num)) {
        printf("%.2lf\n", fabs(num));
    }

    // system("pause");
    return 0;
}