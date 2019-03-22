/**
 * author: xmmmmmovo
 * generation time: 2019/03/22
 * filename: bfs line min step.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>

using namespace std;

int n = 0, A = 0, B = 0, now = 0, step = 0;
queue<pair<int, int>> q;
bool vis[5005];

int main(int argc, char const *argv[]) {
    cin >> n >> A >> B;
    q.push(make_pair(A, 0));
    vis[A] = 1;
    while(!q.empty()){
        now = q.front().first;
        step = q.front().second;
        q.pop();
        if (now == B) {
            return step;
        }
        
        if (now + 1 <= n && !vis[now + 1]) {
            q.push(make_pair(now + 1, step + 1));
            vis[now + 1] = 1;
        }
        if (now - 1 <= n && !vis[now - 1]) {
            q.push(make_pair(now - 1, step + 1));
            vis[now - 1] = 1;
        }
        if (now * 2 <= n && !vis[now * 2]) {
            q.push(make_pair(now * 2, step + 1));
            vis[now * 2] = 1;
        }
    }

    system("pause");
    return 0;
}