// 练习                                组合总和 II 
//                           给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//                           candidates 中的每个数字在每个组合中只能使用 一次 。
//                           注意：解集不能包含重复的组合。 



#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {
        if (sum == target) {
            result.push_back(path);
            return;
        }

        // 剪枝：如果 sum +candidates[i]>target 就终止遍历
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            // 去重逻辑核心:
            // i > startIndex表示不是本层第一个元素
            // candidates[i]==candidates[i- 1]表示和前一个元素相同
            // 此时说明前一个元素在同一层已经被处理过了，当前元素需要跳过
            if (i > startIndex && candidates[i] == candidates[i - 1]) {
                continue;
            }


            sum += candidates[i];
            path.push_back(candidates[i]);


            // i+1：每个数字只能使用一次，所以下一轮从 i+1 开始
            backtracking(candidates, target, sum, i + 1);


            sum -= candidates[i]; // 回溯
            path.pop_back(); // 回溯
        }
    }


public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // 必须排序，以便去重
        backtracking(candidates, target, 0, 0);
        return result;
    }
};