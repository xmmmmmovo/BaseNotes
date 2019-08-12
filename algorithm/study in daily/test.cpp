/**
 * author: xmmmmmovo
 * generation time: 2019/08/02
 * filename: test.cpp
 * language & build version : C++ 11
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {

    int a = 0, b = 0, c = 0;
    double unknow = 0.0;

    scanf("%d %d %d", &a, &b, &c);

    while (a * unknow + b != c) {
        unknow = unknow + 0.01;
    }

    printf("%lf", &unknow);

    return 0;
}