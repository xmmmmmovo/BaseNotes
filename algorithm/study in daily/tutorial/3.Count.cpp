/**
 * author: xmmmmmovo
 * generation time: 2019/03/11
 * filename: 3.Count.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
// #include <algorithm>
#include <string>
#include <vector>

#define STR_M 4096
using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    vector<int> count(26, 0);
    cin >> str; // 输入str

    int temp = 0;

    for(auto& ch : str){
        count[(int)(ch > 'Z' ? ch - 'A' : ch - 'a')]++;
    }

    // size_t 数组下标类型
    for(size_t i = 0; i < count.size(); i++){
        temp = count[i];
        if (!temp) {
            printf("\n");
        }
    }
    

    system("pause");
    return 0;
}