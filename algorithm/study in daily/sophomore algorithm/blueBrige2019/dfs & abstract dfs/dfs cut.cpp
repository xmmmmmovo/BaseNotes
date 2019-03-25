/**
 * author: xmmmmmovo
 * generation time: 2019/03/21
 * filename: dfs cut.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 10;
int n, m, T;
char mat[N][N];
bool vis[N][N];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
bool ok = false;

void dfs(int x, int y, int t) {
    if (ok) {
        return;
    }
    if (t == T) {
        if (mat[x][y] == 'D') {
            ok == true;
        }
    }
    
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx < 0 || tx >= n || ty < 0 || ty >= m
            || mat[tx][ty] == 'X' || vis[tx][ty]) {
                continue;
        }
        dfs(tx, ty, t+ 1);
    }
    vis[x][y] = 0;
}

int main(int argc, char const *argv[]) {
    cin >> n >> m >> T;
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }

    int sx, sy, ex, ey;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'S') {
                sx = i, sy = j;
            }
            if (mat[i][j] == 'D') {
                ex = i, ey = j;
            }
        }
    }

    // 奇偶剪枝
    if ((sx + sy + ex + ey + T) % 2 != 0) {
        cout << "NO" << endl;
    } else {
        ok = false;
        dfs(sx, sy, 0);
        if (ok) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        
    }

    system("pause");
    return 0;
}