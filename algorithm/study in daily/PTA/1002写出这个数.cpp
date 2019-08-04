/**
 * author: xmmmmmovo
 * generation time: 2019/08/02
 * filename: 1002 写出这个数.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    string s[] = {
        "ling",
        "yi",
        "er",
        "san",
        "si",
        "wu",
        "liu",
        "qi",
        "ba",
        "jiu",
    };
    char c = '\0';
    int sum = 0;
    char ans[20];

    while ((c = getchar()) != '\n') {
        sum += c - '0';
    }

    sprintf(ans, "%d", sum);

    // itoa(sum, ans, 10);
    // cout << ans << endl;

    for (auto i = 0; ans[i] != '\0'; i++) {
        if (i > 0) 
            cout << " ";
        cout << s[ans[i]-'0'];
    }

    return 0;
}