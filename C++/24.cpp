#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<vector<int>> cobinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        // 排序以便剪枝
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, path, result);
    }

private:
    void backtrack(vector<int>& candidates, int remain, int start, vector<int>& path, vector<vector<int>>& result) {
        if (remain == 0) {
            result.push_back(path);
            return;
        }


        for (int i = start; i < candidates.size(); ++i) {
            // 剪枝：如果当前数字大于剩余目标值，后面的数字肯定也大于，直接跳出
            if (candidates[i] > remain) {
                break;
            }

            path.push_back(candidates[i]);
            // 递归调用，注意这里传入的是i，因为可以重复使用同一个数字
            backtrack(candidates, remain - candidates[i], i, path, result);
            path.pop_back();
        }
    }
};