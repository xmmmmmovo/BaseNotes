/**
 * author: xmmmmmovo
 * generation time: 2019/04/02
 * filename: D 一道大水题.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
    int n = 0, T = 0;
    int flag = -1;

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);

        if (n < 0) {
            flag = -1;
        } else {
            flag = 1;
        }
        

        for (int i = 2 * flag; i <= n; i += 2 * flag) {
            if (n % i == 0) {
                int y = n / i;
                if (y % 2 != 1) {
                    continue;
                }
                
                printf("%d\n", n / i);
                break;
            }
        }
    }

    // system("pause");
    return 0;
}