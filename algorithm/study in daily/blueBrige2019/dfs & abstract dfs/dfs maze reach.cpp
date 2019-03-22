/**
 * author: xmmmmmovo
 * generation time: 2019/03/19
 * filename: dfs mapsearch.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n, m, x, y;
string maze[110];
bool vis[110][110];

bool in(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool dfs(int x, int y){
    if (maze[x][y] == 'T') {
        return true;
    }

    vis[x][y] = 1;
    maze[x][y] = 'm';
    
    int dx = x, dy = y + 1;
    if (in(dx, dy) && maze[dx][dy] != '*' && !vis[dx][dy]) {
        if (dfs(dx, dy)) {
            return true;
        }
    }

    dx = x, dy = y - 1;
    if (in(dx, dy) && maze[dx][dy] != '*' && !vis[dx][dy]) {
        if (dfs(dx, dy)) {
            return true;
        }
    }

    dx = x - 1, dy = y;
    if (in(dx, dy) && maze[dx][dy] != '*' && !vis[dx][dy]) {
        if (dfs(dx, dy)) {
            return true;
        }
    }

    dx = x + 1, dy = y;
    if (in(dx, dy) && maze[dx][dy] != '*' && !vis[dx][dy]) {
        if (dfs(dx, dy)) {
            return true;
        }
    }
    
    vis[x][y] = 0;
    maze[x][y] = '.';
    return false;
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> maze[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == 'S') {
                x = i, y = j;
            }
        }
    }
    
    printf("\n");
    if (dfs(x, y)) {
        for (int i = 0; i < n; i++) {
            cout << maze[i] << endl;
        }
    } else {
        cout << "can't reach!";
    }
    
    system("pause");
    return 0;
}