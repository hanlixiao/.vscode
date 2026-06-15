#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(n, k, 1, path, res);
        return res;
    }

private:
    void backtrack(int n, int k, int start, vector<int>& path, vector<vector<int>>& res) {
        // 终止条件：组合长度达到k
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        // 剪枝：剩余数字数量不足时停止
        // 剩余需要选的数量：k- path.size()
        // 最大起始位置：n-(k- path.size()）+1
        for (int i = start; i <= n - (k - path.size()) + 1; ++i) {
            path.push_back(i);  //选择当前数字
            backtrack(n, k, i + 1, path, res);  // 递归，下一个数字从i+1开始
            path.pop_back();  //回溯，撤销选择
        }
    }
};