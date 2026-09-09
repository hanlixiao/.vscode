// 练习                                                       组合总和 III
//                                             找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：
//                                             只使用数字1到9
//                                             每个数字 最多使用一次 
//                                             返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    // start：从哪个数字开始选；k要选k个；n目标和；sum当前累加和
    void backtrack(int start, int k, int n, int sum) {
        // 选够k个数字
        if (path.size() == k) {
            if (sum == n) {
                res.push_back(path);
            }
            return;
        }
        // 从start到9遍历
        for (int i = start; i <= 9; i++) {
            // 剪枝：加上i已经超过目标，后面更大的数不用试了
            if (sum + i > n) break;

            path.push_back(i);  // 选i
            backtrack(i + 1, k, n, sum + i);  // 下—轮从i+1开始，不能重复选
            path.pop_back();  // 回溯，撤销选择
        }
    }

    vector<vector<int>> combinatonSum3(int k, int n) {
        res.clear();
        path.clear();
        backtrack(1, k, n, 0);
        return res;
    }
};