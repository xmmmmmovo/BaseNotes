/**
 * author: xmmmmmovo
 * generation time: 2019/03/25
 * filename: D.数的分解.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int check(int x) {              //判断x是否满足
    while (x) {
        int t = x % 10;
        if (t == 2 || t == 4)return 0;
        x /= 10;
    }
    return 1;
}

int num[4000];

int main(int argc, char const *argv[]) {
    int ans = 0;
    for (int i = 1; i < 2019; i++) {
        if (check(i)) {
            num[ans ++] = i;
        }
    }

    int k = 0;

    for (int i = 0; i < ans; i++) {
        for (int j = i + 1; j < ans; j++) {
            for (int l = j + 1; l < ans; l++) {
                if (num[i] + num[j] + num[l] == 2019) {
                    k++;
                }
            }
        }
    }

    printf("%d\n", k);

    system("pause");
    return 0;
}