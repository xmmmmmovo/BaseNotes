/**
 * author: xmmmmmovo
 * generation time: 2019/03/22
 * filename: bfs maze.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, x, y;
string maze[110];
bool vis[110][110];
int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

bool in(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

struct node{
    int x, y, d;
    node(int xx, int yy, int dd) {
        x = xx;
        y = yy;
        d = dd;
    }
};

int bfs(int sx, int sy) {
    queue<node> q;
    q.push(node(sx, sy, 0));
    vis[sx][sy] = 1;
    while(!q.empty()){
        node now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int tx = now.x + dir[i][0];
            int ty = now.y + dir[i][1];

            if (in(tx, ty) && maze[tx][ty] != '*' && !vis[tx][ty]) {
                if (maze[tx][ty] == 'T') {
                    return now.d + 1;
                } else {
                    vis[tx][ty] = 1;
                    q.push(node(tx, ty, now.d + 1));
                }   
            }
        }
    }

    return -1;
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

    cout << bfs(x, y) << endl;
    
    system("pause");
    return 0;
}