/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */
#include <vector>
using namespace std;
class Solution {
public:
    int dfs(vector<vector<int>>& triangle, int floor, int left, int right) {
            // 判断是否最下层也计算过了
            if (floor == triangle.size()) {
                return 0;
            }

            int tl = 0, tr = 0;
            int ans = 0;
            if (left < floor + 1)
                tl = dfs(triangle, floor + 1, left, left + 1) + triangle[floor][left];

            if (right < floor + 1)
                tr = dfs(triangle, floor + 1, right, right + 1) + triangle[floor][right];

            return ans + min(tl, tr);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        return dfs(triangle, 1, 0, 1) + triangle[0][0];
    }
};

