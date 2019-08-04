/**
 * author: xmmmmmovo
 * generation time: 2019/08/03
 * filename: 1003我要通过！.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

bool check(string &s) {
    bool p_check = false, t_check = false;

    for (auto &ch : s) {
        // 如果不是PAT直接判错
        if (ch != 'P' || ch != 'A' || ch != 'T') {
            return false;
        }

        if (ch == 'P') {
            p_check= true;
        }

        if (ch == 'T') {
            t_check = true;
        }

        if (ch == 'A' && p_check) {
        }

    }

    
    return true;
}

int main() {
    int n = 0;
    cin >> n;

    while (n--) {
        string s;
        getline(cin, s); // 从标准输入中读取一行

        if (check(s)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}