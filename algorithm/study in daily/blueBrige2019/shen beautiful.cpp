/**
 * author: xmmmmmovo
 * generation time: 2019/03/17
 * filename: shen beautiful.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int ans = 0; // 答案
    int m = 0, n = 0;   

    scanf("%d %d", &n, &m);

    int a[n][m];

    // 读入画作
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &a[n][m]);
        }
    }

    system("pause");
    return 0;
}