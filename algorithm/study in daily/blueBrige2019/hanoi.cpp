/**
 * author: xmmmmmovo
 * generation time: 2019/03/19
 * filename: hanoii.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>

using namespace std;

//这里表示三根柱子
stack<int> st[3];

void move(int x, int y){
    int temp = st[x].top();
    st[x].pop();
    st[y].push(temp);
    cout << x << "-->" << y << endl;
}

void hanoi(int A, int B, int C, int n){
    if (n == 1) {
        move(A, C);
        return;
    }
    
    hanoi(A, C, B, n - 1);
    move(A, C);
    hanoi(B, A, C, n - 1);
}

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    for(int i = n; i >= 1; i--){
        st[0].push(i); // 倒置入栈
    }
    
    hanoi(0, 1, 2, n);
    while(!st[2].empty()){
        cout << st[2].top() << " ";
        st[2].pop();
    }

    system("pause");
    return 0;
}