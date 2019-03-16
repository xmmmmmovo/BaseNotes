/**
 * author: xmmmmmovo
 * generation time: 2019/03/15
 * filename: 2001 计算两点间的距离.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    double x1, y1, x2, y2;
    double ans = 0;

    while(~scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2)){
        ans = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
        printf("%.2lf\n", ans);
    }

    // system("pause");
    return 0;
}