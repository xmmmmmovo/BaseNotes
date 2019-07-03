/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string ans;
        stack<char> buf;

        for (auto &ch : path) {
            switch (ch)
            {
            case '/':
                if (buf.empty()) {
                    ans.push_back(ch);
                }
                break;
            case '.':
                if (buf.top() == '/') {

                }
                break;
            default:
                buf.push(ch);
                break;
            }
        }
    }
};

