/**
 * author: xmmmmmovo
 * generation time: 2019/03/11
 * filename: test.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[])
{
    int sum = 0, temp = 0, n = 370;

    while (n) {
        temp = n % 10;
        sum += temp * temp * temp;
        n /= 10;
    }

    printf("%d", sum == n);

    system("pause");
    return 0;
}