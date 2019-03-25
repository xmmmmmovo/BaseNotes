/**
 * author: xmmmmmovo
 * generation time: 2019/03/21
 * filename: boom search.cpp
 * language & build version : C++ 11
*/
/**
 * 为了引爆所有炸弹的最少引爆炸弹次数
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n, m;
char mat[1010][1010];
bool row[1010], col[1010];

void boom(int x, int y) {
    mat[x][y] = 0; // 访问过
    if (!row[x]) {
        row[x] = 1;
        for (int i = 0; i < m; i++) {
            if (mat[x][i] == '1') {
                boom(x, i);
            }
        }
    }
    if (!col[y]) {
        col[y] = 1;
        for (int i = 0; i < n; i++) {
            if (mat[i][y] == '1') {
                boom(i, y);
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 如果有炸弹便开炸
            if (mat[i][j] == '1') {
                ++cnt;
                boom(i, j);
            }
        }
    }

    cout << cnt << endl;

    system("pause");
    return 0;
}