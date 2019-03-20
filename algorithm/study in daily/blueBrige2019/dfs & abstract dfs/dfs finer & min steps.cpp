/**
 * author: xmmmmmovo
 * generation time: 2019/03/20
 * filename: dfs finer & min steps.cpp
 * language & build version : C++ 11
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n, m;
string maze[110];
bool vis[110][110];
int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int ans = 10000000000;

bool in(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y, int step){
	if (maze[x][y] == 'T') {
		if (ans > step) {
			ans = step;
		}
		return;
	}
	vis[x][y] = 1;
	for (int i = 0; i < 4; ++i) {
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		if (in(tx, ty) && maze[tx][ty] != '*' && !vis[tx][ty]){
			dfs(tx, ty, step + 1);
		}
	}
	vis[x][y] = 0;
}

int main() {
	int x = 0, y = 0;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> maze[i];	
	}
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (maze[i][j] == 'S') {
				x = i, y = j;
			}
		}
	}
	dfs(x, y, 0);
	cout << ans << endl;
	
	return 0;
}