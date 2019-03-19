/**
 * author: xmmmmmovo
 * generation time: 2019/03/19
 * filename: train exc.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;

    // 这里输入的是给定的顺序
    vector<int> trains(n);
    for(int i = 0; i < n; i++){
        cin >> trains[i];
    }

    stack<int> s;
    int cur = 1;
    bool f = 1;
    for(int i = 0; i < n; i++){
        // 压栈
        while((s.empty() || s.top() != trains[i]) && cur <= n){
            s.push(cur);
            cur ++;
        }

        // 这里判断栈顶是不是train[i]
        if(s.empty() || s.top() != trains[i]){
            f = 0;
            break;
        }else{
            s.pop();
        }
    }

    if(f){
        cout << "legal" << endl;
    }else{
        cout << "inlegal" << endl;
    }
    

    system("pause");
    return 0;
}