/**
 * author: xmmmmmovo
 * generation time: 2019/03/20
 * filename: dfs stick tri.cpp
 * language & build version : C++ 11
*/
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int p[15];
int n, sum = 0;

bool f = false;
bool vis[15];

void dfs(int cnt, int s, int st) {
	if (f) {
		return;
	}
	if (cnt == 3) {
		f = true;
		return;
	}
	if (s == sum / 3) {
		dfs(cnt + 1, 0, 0);
		return;
	}
	
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			dfs(cnt, s + p[i], i + 1);
			vis[i] = 0;
		}
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
		sum += p[i];
	}
	
	if (sum % 3 != 0) {
		printf("no\n");
	} else {
		dfs(0, 0, 0);
		if (f) {
			printf("yes\n");
		} else {
			printf("no\n");
		}
	}
	
    system("pause");
	return 0;
}