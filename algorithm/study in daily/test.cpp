/**
 * author: xmmmmmovo
 * generation time: 2019/08/02
 * filename: test.cpp
 * language & build version : C++ 11
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
    int n[10];

    for (int i = 0; i < 10; i++) {
        cin >> n[i];
    }

    cout << "max" << *max_element(n, n+10) << "min" << *min_element(n, n +10) << endl;

    return 0;
}