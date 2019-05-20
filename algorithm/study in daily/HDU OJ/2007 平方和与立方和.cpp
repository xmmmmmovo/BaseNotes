/**
 * author: xmmmmmovo
 * generation time: 2019/05/20
 * filename: 2007 平方和与立方和.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
    int ji_sum = 0, ou_sum = 0, start = 0, end = 0;

    while (cin >> start >> end) {
        // bool start_ji_flag = false, start_ou_flag = false;
        // bool end_ji_flag = false, end_ou_flag = false;
        // if () {
        // }

        // 重置
        ji_sum = 0, ou_sum = 0;
        /**
         * 这里一定要注意说明
         * 并不是一定左边大于右边
         * 有可能是反过来得
        */
        if (start > end) {
            swap(start, end);
        }
        
        for (int i = start; i <= end; i++) {
            if (i % 2 == 0) {
                ou_sum += i * i;
            }
            if (abs(i % 2) == 1) {
                ji_sum += i * i * i;
            }
        }

        cout << ou_sum << " " << ji_sum << endl;
    } 

    // system("pause");
    return 0;
}