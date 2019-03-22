/**
 * author: xmmmmmovo
 * generation time: 2019/03/22
 * filename: 2n queen.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n = 0;
bool map[10][10];
int vx[10], vy[10], vd1[20], vd2[20];

int main(int argc, char const *argv[]) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	system("pause");
	return 0;
}