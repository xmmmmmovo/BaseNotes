/**
 * author: xmmmmmovo
 * generation time: 2019/03/25
 * filename: C.数列求和.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
    int a = 1, b = 1, c = 1;
    int temp = 0;

    for (int i = 4; i <= 20190324; i++) {
        temp = a + b + c;
        temp %= 10000;
        c = b;
        b = a;
        a = temp;
        // printf("%d %d\n", temp, i);
    }

    printf("%d", a);

    system("pause");
    return 0;
}