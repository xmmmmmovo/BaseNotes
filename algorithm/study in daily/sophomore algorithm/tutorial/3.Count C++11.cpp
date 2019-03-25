/**
 * author: xmmmmmovo
 * generation time: 2019/03/11
 * filename: 3.Count.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    vector<int> count(26, 0);
    cin >> str; // 输入str

    int temp = 0;

    for(auto& ch : str){
        if (ch > 'A' && ch < 'Z') {
            count[(int)ch - 'A']++;
        }else if(ch > 'a' && ch < 'z'){
            count[(int)ch - 'a']++;   
        }
    }

    for(size_t i = 0; i < count.size(); i++){
        temp = count[i];
        if (temp) {
            printf("%c: %d\n", i + 'A', temp);
        }
    }

    // system("pause");
    return 0;
}