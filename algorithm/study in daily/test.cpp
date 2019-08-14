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

    scanf("%d%d%d", &a, &b, &c);

    printf("%d", max(a, max(b, c)));

    return 0;
}