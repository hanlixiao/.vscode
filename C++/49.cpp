// 练习                                       子集
//                                     给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
//                                     解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。 



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(nums, 0, path, res);
        return res;
    }

private:
    void backtrack(vector<int>& nums, int start ,vector<int>& path, vector<vector<int>>& res) {
        // 当前path就是一个子集，直接记录
        res.push_back(path);
        // 从start开始遍历，只取后面元素，防止重复
        for (int i = start; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            backtrack(nums, i + 1, path, res);
            path.pop_back();  // 回溯撤销
        }
    }
};