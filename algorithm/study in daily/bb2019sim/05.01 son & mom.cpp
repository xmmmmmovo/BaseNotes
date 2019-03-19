/**
 * author: xmmmmmovo
 * generation time: 2019/03/18
 * filename: 05.01 son & mom.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int tol = 0;
    for(int i = 27; i < 100; i++){
        if ((i - (i % 10 * 10 + i / 10)) == 27) {
            tol ++;
        }
    }
    printf("%d\n", tol);

    system("pause");
    return 0;
}