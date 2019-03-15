/**
 * author: xmmmmmovo
 * generation time: 2019/03/15
 * filename: Num Sum.cpp
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
    int n;
    double ans = 0, a1 = 0;

    while(~scanf("%lf %d", &a1, &n)){
        ans = a1;
        while(--n){
            a1 = sqrt(a1);
            ans += a1;
        }

        printf("%.2lf\n", ans);
    }
    return 0;
}