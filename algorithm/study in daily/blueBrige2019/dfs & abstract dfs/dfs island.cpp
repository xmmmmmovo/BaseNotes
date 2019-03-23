// /**
//  * author: xmmmmmovo
//  * generation time: 2019/03/23
//  * filename: dfs island.cpp
//  * language & build version : C++ 11
// */
// #include <iostream>
// #include <cstdio>
// #include <cstdlib>
// #include <algorithm>
// #include <string>

// using namespace std;

// string sea[1005];
// bool vis[1005][1005];
// int N = 0, cnt = 0, re = 0;
// int isl[10005];
// int dir[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

// bool in(int x, int y) {
//     return x >= 0 && x < N && y >= 0 && y < N;
// }

// void dfs(int x, int y, int num) {
//     if (sea[x][y] == '.') {
//         return;
//     }
//     if (vis[x][y]) {
//         return;
//     }

//     vis[x][y] = 1;

//     if (in(x, y - 1) && in(x + 1, y) && in(x - 1, y) && in(x, y + 1) && 
//         sea[x][y - 1] == '#' && sea[x + 1][y] == '#' &&
//         sea[x - 1][y] == '#' && sea[x][y + 1] == '#') {
//             isl[num] ++;
//     }

//     for (int i = 0; i < 4; i++) {
//         int tx = dir[i][0];
//         int ty = dir[i][1];
//         if (in(tx, ty) && sea[tx][ty] != '.' && !vis[tx][ty]){
// 			dfs(tx, ty, num);
// 		}
//     }    
// }

// int main(int argc, char const *argv[]) {
//     cin >> N;
//     for (int i = 0; i < N; i++) {
//         cin >> sea[i];
//     }

//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             if (!vis[i][j] && sea[i][j] == '#') {
//                 dfs(i, j, cnt);
//                 cnt ++; // 找到便++
//             }
//         }
//     }

//     for (int i = 0; i < cnt; i++) {
//         if (isl[i] == 0) {
//             re ++;
//         }
//     }

//     cout << re << endl;

//     system("pause");
//     return 0;
// }

#include<iostream>
#include<cstdio>
using namespace std;
int mp[110][110];
int ans[11000];
bool vis[110][110];
void dfs(int x,int y,int k)
{
    if(mp[x][y]=='.')
        return;
    if(vis[x][y])
        return;
    vis[x][y]=1;
    if(mp[x-1][y]=='#'&&mp[x+1][y]=='#'&&mp[x][y-1]=='#'&&mp[x][y+1]=='#')
        ans[k]++;
    dfs(x+1,y,k);
    dfs(x-1,y,k);
    dfs(x,y-1,k);
    dfs(x,y+1,k);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        getchar();
        for(int j=1;j<=n;j++)
            scanf("%c",&mp[i][j]);

    }
    int len=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(mp[i][j]=='#'&&!vis[i][j])
            {
                dfs(i,j,len);
                len++;
            }
        }
    }
    int sum=0;
    for(int i=0;i<len;i++)
        if(ans[i]==0)
            sum++;
    printf("%d\n",sum);

    system("pause");
}