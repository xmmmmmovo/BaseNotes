/**
 * author: xmmmmmovo
 * generation time: 2019/03/13
 * filename: 2.moha.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int high = 60405, up = 105, down = 35;
    int height = 0, day = 0;

    while(true){
        day++;
        height += up;
        if (height >= high) {
            break;
        }
        height -= down;
    }

    printf("%d\n", day);

    system("pause");
    return 0;
}