/**
 * author: xmmmmmovo
 * generation time: 2019/03/16
 * filename: E Digital Roots.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    int num = 0; // counts
    // int ans = 0;
    while(cin >> str && str != "0") {
        num = 0;

        // 逐加
        for(int i = 0; i < str.length(); i++){
            num += str[i] - '0';
            if (num >= 10) {
                num = num / 10 + num % 10;
            }
        }
        
        printf("%d\n", num);
    }
    // system("pause");
    return 0;
}