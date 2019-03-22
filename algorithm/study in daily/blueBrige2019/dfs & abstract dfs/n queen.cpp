/**
 * author: xmmmmmovo
 * generation time: 2019/03/20
 * filename: n queen.cpp
 * language & build version : C++ 11
*/
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int ans = 0;
bool col[10], x1[20], x2[20]; // x1, x2是对角线

bool check(int r, int i) {
	return !col[i] && !x1[r + i] && !x2[r - i + 8];
}

void dfs(int r) {
	if (r == 8) {
		ans ++;
		return;
	}
	
	for (int i = 0; i < 8; i++) {
		if(check(r, i)) {
			col[i] = x1[r + i] = x2[r - i + 8] = 1;
			dfs(r + 1);
			col[i] = x1[r + i] = x2[r - i + 8] = 0;
		}
	}
}

int main(){
	
	dfs(0);
	cout << ans << endl;
	
    system("pause");
	return 0;
}