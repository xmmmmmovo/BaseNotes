/**
 * author: xmmmmmovo
 * generation time: 2019/03/15
 * filename: D Let the Ballon Rise.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    int N = 0;

    while(~scanf("%d", &N)) {
        if (N == 0) {
            break;
        }

        map<string, int> colors;
        string tempstr;
        map<string, int>::iterator iter;

        while(N--){
            cin >> tempstr;

            if ((iter = colors.find(tempstr)) == colors.end()) {
                colors.insert(pair<string, int>(tempstr, 1)); // 插入
            }else {
                (*iter).second ++;
            }
        }

        iter = colors.begin();
        int max = (*iter).second;
        tempstr = (*iter).first;

        // 遍历
        for(; iter != colors.end(); iter++){
            if (max < (*iter).second) {
                max = (*iter).second;
                tempstr = (*iter).first;
            }
        }

        cout << tempstr << endl;   
    }

    // system("pause");
    return 0;
}