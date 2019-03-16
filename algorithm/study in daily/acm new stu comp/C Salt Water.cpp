/**
 * author: xmmmmmovo
 * generation time: 2019/03/15
 * filename: C Salt Water.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    double D = 0, VUL = 0;
    int times = 0, seconds = 0, temp = 0;

    while(~scanf("%lf %lf", &VUL, &D)){
        // 初始化
        times = 1;
        seconds = 0;
        while(true){
            temp = times;
            while(temp--){
                seconds ++;
                VUL -= D;
                if (VUL <= 0) {
                    break;
                }
            }

            if (VUL <= 0) {
                break;
            }
            
            times ++; // 累加器
            seconds ++; // 停留计时
        }
        printf("%d\n", seconds);
    }

    // system("pause");
    return 0;
}