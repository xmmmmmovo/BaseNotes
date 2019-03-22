/**
 * author: xmmmmmovo
 * generation time: 2019/03/16
 * filename: 2n queen.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n = 0;
bool chess[10][10];
int ans = 0;
bool col[10], x1[20], x2[20]; // x1, x2是对角线
bool blcheck = false;

bool check(int r, int i) {
	return !col[i] && !x1[r + i] && !x2[r - i + n] && chess[r][i];
}

// r chess
void dfs(int r, int l) {
	if (r == n) {
		if (blcheck) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					cout << chess[i][j];
				}
				cout << endl;
			}
			ans += 2;
			blcheck = false;
			cout << endl;
		} else {
			chess[n - 1][l] = 0;
			blcheck = true;
			for (int i = 0; i < 20; i++) {
				x1[i] = 0;
			}
			for (int i = 0; i < 20; i++) {
				x2[i] = 0;
			}
			dfs(0, 0);
			chess[n - 1][l] = 1;
		}
		// cout << endl;
		return;
	}
	
	for (int i = 0; i < n; i++) {
		if(check(r, i)) {
			col[i] = x1[r + i] = x2[r - i + n] = 1;
			chess[r][i] = 0;
			dfs(r + 1, i);
			col[i] = x1[r + i] = x2[r - i + n] = 0;
			chess[r][i] = 1;
		}
	}
}

int main(){
	cin >> n;

	// 读入chess
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> chess[i][j];
		}
	}

	dfs(0, 0);
	cout << ans << endl;
	
    system("pause");
	return 0;
}
// #include <cmath>
// #define MAXSIZE 1000
// int bqueen[MAXSIZE];//黑皇后
 
// int wqueen[MAXSIZE];//白皇后
 
// int chessboard[MAXSIZE][MAXSIZE];//1:能放  0:不能放  
// int cnt = 0;
 
// int n;
 
// int place(int k);
 
// int BlackQueen(int k)
// {
//     int i;
//     int j;
//     for(i =0; i < k -1; i++)
//     {
//         int judge = bqueen[i]- bqueen[k -1];
//         if(judge ==0|| fabs(k -1- i)== fabs(judge))
//             return 0;
//     }
 
//     if(k == n)
//     {
//         cnt++;
//         return 0;
//     }
 
//     for( j =0; j < n; j++)
//     {
//         if(j != wqueen[k]&& chessboard[k][j])
//         {
//             bqueen[k]= j;
//             BlackQueen(k +1);
//         }
//     } 
// }
 
// int WhiteQueen(int k)
 
// {
 
//     int i;
 
//     int j;
 
//     for( i =0; i < k -1; i++)
 
//     {
 
//         int judge = wqueen[i]- wqueen[k -1];
 
//         if(judge ==0|| fabs(k -1- i) == fabs(judge))
 
//             return 0;
 
//     }
 
//     if(k == n)
 
//     {
 
//         BlackQueen(0);
 
//         return 0;
 
//     }
 
//     for( j =0; j < n; j++)
 
//     {
 
//         if(chessboard[k][j])
 
//         {
 
//             wqueen[k]= j;
 
//             WhiteQueen(k +1);
 
//         }
//     }
// }
// int main(void)
 
// {   int i;
 
//     int j;
 
//    // freopen("input3.txt","r",stdin);//这是我直接从文件中读取数据
 
//     scanf("%d",&n);
 
//     for(i =0; i < n; i++)
 
//         for(j =0; j < n; j++)
 
//         scanf("%d",&chessboard[i][j]);
 
//     WhiteQueen(0);
 
//     printf("%d\n",cnt);
 
 
// 	system("pause");
//     return 0;
// }