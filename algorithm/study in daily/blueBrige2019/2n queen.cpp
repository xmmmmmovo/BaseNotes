/**
 * author: xmmmmmovo
 * generation time: 2019/03/16
 * filename: 2n queen.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int chess[10][10], bqueen[10], wqueen[8]; 

int main(){
    int n = 0;
    scanf("%d", &n);

    // 存储chess
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &chess[i][j]);
        }
    }

    system("pause");
    return 0;
}