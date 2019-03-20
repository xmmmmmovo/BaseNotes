/**
 * author: xmmmmmovo
 * generation time: 2019/03/19
 * filename: hanoi2.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;
long long int f[65], g[65];

int main(int argc, char const *argv[])
{
    int n = 0;
    scanf("%d", &n);
    f[1] = 1;
    
    for(int i = 2; i <= n; i++){
        f[i] = 2 * f[i - 1] + 1;
    }

    g[1] = 1;
    for(int i = 0; i <= n; i++){
        g[i] = 2 * g[i - 1] + i;
    }

    printf("%lld %lld\n", f[n], g[n]);

    system("pause");
    return 0;
}