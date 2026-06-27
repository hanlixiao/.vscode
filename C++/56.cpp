#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        sort(nums.begin(), nums.end());  // 排序，让重复元素相邻
        backtrack(nums, 0, path, res);
        return res;
    }

private:
    void backtrack(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& res) {
        // 每条路径都是合法子集
        res.push_back(path);
        for (int i = start; i <nums.size(); ++i) {
            // 去重：同层，i>start说明前一个同数字未选取，跳过
            if (i > start && nums[i] == nums[i - 1]) continue;
            path.push_back(nums[i]);
            backtrack(nums, i + 1, path, res);
            path.pop_back();  // 回溯撤销
        }
    }
};