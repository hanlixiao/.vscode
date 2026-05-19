// 练习                                    全排列
//                            给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        // 用来标记数字是否被用过
        vector<bool> used(nums.size(), false);

        backtracking(nums, used, path, result);

        return result;
    }

private:
    void backtracking(vector<int>& nums, vector<bool>& used, vector<int>& path, vector<vector<int>>& result) {
        // 1。终止条件：路径长度等于数组长度，说明找到了一组全排列
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        // 2.单层搜索逻辑
        for (int i = 0; i < nums.size(); i++) {
            // 如果当前数字已经被用过了，就跳过
            if (used[i] == true) {
                continue;
            }

            // 做选择
            used[i] = true; // 标记为已用
            path.push_back(nums[i]); // 加入路径

            // 递归
            backtracking(nums, used, path, result);

            // 撤销选择（回溯的核心）
            path.pop_back(); // 移除最后一个元素
            used[i] = false; // 恢复标记，以便下一次循环使用
        }
    }
};