/**
 * author: xmmmmmovo
 * generation time: 2019/04/22
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

int main(int argc, char const *argv[]) {
    vector<int> vec;

    for (int i = 0; i < 100; i++) {
        vec.push_back(i + 1);
    }

    random_shuffle(vec.begin(), vec.end());

    for (auto &elem : vec) {
        cout << elem << " ";
    }

    cout << endl;
    cout << endl;

    vec.resize(10);

    for (auto &elem : vec) {
        cout << elem << " ";
    }



    system("pause");
    return 0;
}