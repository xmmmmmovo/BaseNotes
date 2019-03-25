/**
 * author: xmmmmmovo
 * generation time: 2019/03/20
 * filename: dfs num sums.cpp
 * language & build version : C++ 11
*/
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n, k, sum, ans;
int nums[40];

void dfs(int i, int cnt, int s){
	if (i == n) {
		if (cnt == k && s == sum) {
			ans ++;
		}
		return;
	}
	dfs(i + 1, cnt, s);
	dfs(i + 1, cnt + 1, s + nums[i]);
}

int main(){
	cin >> n >> k >> sum;
	for	(int i = 0; i < n; i++)	{
		cin >> nums[i];
	}
	ans = 0;
	dfs(0, 0, 0);
	cout << ans << endl;
	
    system("pause");
	return 0;
}