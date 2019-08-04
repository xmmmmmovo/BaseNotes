/**
 * author: xmmmmmovo
 * generation time: 2019/08/02
 * filename: 1001 害死人不偿命的(3n+1)猜想.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
    int n = 0, cnt = 0;
    
    cin >> n;
    while (n != 1) {
        cnt ++;
        // cout << (n % 3) << endl;
        if (n % 2 == 1) {
            n = (3 * n + 1) / 2;
        } else {
            n /= 2;
        }
    }
    cout << cnt << endl;
    

    return 0;
}