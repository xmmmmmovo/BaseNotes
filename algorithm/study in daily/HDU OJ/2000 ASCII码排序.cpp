/**
 * author: xmmmmmovo
 * generation time: 2019/03/17
 * filename: 2000 ASCII码排序.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

char chs[3];

int main(int argc, char const *argv[])
{
    while(~scanf("%c%c%c", chs, chs + 1, chs + 2)){
        sort(chs, chs + 3);
        printf("%c %c %c\n", chs[0], chs[1], chs[2]);
        getchar();
    }    

    // system("pause");
    return 0;
}