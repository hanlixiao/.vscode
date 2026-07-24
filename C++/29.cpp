// 练习                                       全排列 II 
//                              给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> used(nums.size(), false);

        // 1。排序是让重复元素相邻的前提
        sort(nums.begin(), nums.end());
        
        backtrack(nums, used, path, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& path, vector<vector<int>> result) {
        // 结束条件
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            // 如果当前数字已经用过了，跳过
            if (used[i]) continue;

            // 2．核心剪枝逻辑：去重
            // 如果当前数字和前一个数字相同，且前一个数字在这一层还没被用（或者刚被撤销）
            // 说明我们在尝试重复的分支，直接跳过
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }

            // 做选择
            used[i] = true;
            path.push_back(nums[i]);

            // 递归
            backtrack(nums, used, path, result);

            // 撤销选择（回溯)
            used[i] = false;
            path.pop_back();
        }
    }
};