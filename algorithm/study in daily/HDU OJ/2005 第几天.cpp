/**
 * author: xmmmmmovo
 * generation time: 2019/05/20
 * filename: 2005 第几天.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

bool IsMonth(int i) {
    if (i == 1 
    || i == 3 || i == 5 || i == 7 || i == 8
    || i == 10 || i == 12) {
        return true;
    }

    return false;
}

int main(int argc, char const *argv[]) {
    int w = 0, d = 0, m = 0, y = 0;
    int ans = 0;
    while (~scanf("%d/%d/%d", &y, &m, &d)) {
        ans = 0;
        for (int i = 1; i < m; i++) {
            if (IsMonth(i)) {
                ans += 31;
                continue;
            }

            if (i == 2) {
                if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) {
                    ans += 29;
                } else {
                    ans += 28;  
                }
                
                continue;
            }
            
            ans += 30;
        }

        ans += d;

        cout << ans << endl;
    }

    // system("pause");
    return 0;
}