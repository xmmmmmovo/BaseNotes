/**
 * author: xmmmmmovo
 * generation time: 2019/05/20
 * filename: test.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> match(string &s1, string &s2) {
    vector<int> match_position;
    vector<int> disc(26, s2.length());

}

int main(int argc, char const *argv[]) {
    string s1, s2;
    cin >> s1 >> s2; 

    vector<int> m = match(s1, s2);

    system("pause");
    return 0;
}