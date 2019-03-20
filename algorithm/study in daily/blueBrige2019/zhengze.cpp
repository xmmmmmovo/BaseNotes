/**
 * author: xmmmmmovo
 * generation time: 2019/03/19
 * filename: zhengze.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int fun(){
    char data;
    int x = 0, y = 0;
    while (true) {
        data = getchar();
        if (data == 'x') {
            x ++;
        } else if (data == '|') {
            // 在这里转移到了y变量上
            // 就是说以后如果继续累加x变量便可以计算右边的字符数了
            y = max(x, y);
            x = 0;
        } else if (data == '(') {
            x += fun();
        } else {
            y = max(x, y);
            return y;
        }
    }
}

int main(int argc, char const *argv[])
{
    printf("%d", fun());

    system("pause");
    return 0;
}