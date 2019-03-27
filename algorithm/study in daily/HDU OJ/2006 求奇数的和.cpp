/**
 * author: xmmmmmovo
 * generation time: 2019/03/27
 * filename: 2006 求奇数的和.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    while (~scanf("%d", &n)) {
        vector<int> nums(n, 0);
        int ans = 1;
        for (int i = 0; i < n; i++) {
            scanf("%d", &nums[i]);
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 != 0) {
                ans *= nums[i];
            }
        }

        printf("%d\n", ans);
    }

    // system("pause");
    return 0;
}