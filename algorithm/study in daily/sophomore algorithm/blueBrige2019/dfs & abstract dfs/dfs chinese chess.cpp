/**
 * author: xmmmmmovo
 * generation time: 2019/03/20
 * filename: dfs chinese chess.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

char chess[10][10]; // 棋盘
int dir[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, 
                {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
bool f = false;
bool vis[10][10];

bool in(int x, int y){
    return x >= 0 && x < 10 && y >= 0 && y < 9;
}

void dfs(int x, int y){
    vis[x][y] = 1;
    if (f) {
        return;
    }
    
    if (chess[x][y] == 'T') {
        f = 1;
        return;
    }
    

    for (int i = 0; i < 8; i++) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];

        if (in(tx, ty) && chess[tx][ty] != '#' && !vis[tx][ty]) {
            dfs(tx, ty);
        }
    }
}

int main(int argc, char const *argv[])
{
    int x = 0, y = 0;

    for (int i = 0; i < 10; i++) {
        scanf("%s", chess[i]);
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            if (chess[i][j] == 'S') {
                x = i, y = j;
            }
        }
    }

    dfs(x, y);

    if (f) {
        printf("yes");
    } else {
        printf("no");
    }
    

    system("pause");
    return 0;
}