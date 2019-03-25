/**
 * author: xmmmmmovo
 * generation time: 2019/03/16
 * filename: F 3 foots.cpp
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
    int ans = 0, t = 0;
    double s = 0, u = 0, v = 0;

    scanf("%d", &t);
    while(t--){
        scanf("%lf %lf", &s, &u);

        v = 1.0/(tan(atan(1.0/s) - atan(1.0/u)));

        printf("%.f\n", (v * u - s * u - s * v));
    }

    // system("pause");
    return 0;
}