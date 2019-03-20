/**
 * author: xmmmmmovo
 * generation time: 2019/03/20
 * filename: dfs num sums finer.cpp
 * language & build version : C++ 11
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int n, k, sum, ans = 0;
int nums[40];
bool choose[40];

void dfs(int s, int cnt){
	if (cnt == k) {
		if (s == sum) {
			ans ++;
		}
		return;
	}
	
	for (int i = 0; i < n; i ++) {
		if (!choose[i]){
			choose[i] = 1;
			dfs(s + nums[i], cnt + 1);
			choose[i] = 0;
		}
	}
}

int main(){
	cin >> n >> k >> sum;
	for	(int i = 0; i < n; i++)	{
		cin >> nums[i];
	}
	
	ans = 0; 
	dfs(0, 0);
	cout << ans << endl;
	
    system("pause");
	return 0;
}