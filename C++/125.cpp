//练习                                          组合总和 III
//                               找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：
//                               只使用数字1到9
//                               每个数字 最多使用一次 
//                               返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void backtrack(int start, int k, int n, int sum) {
        // 选够k个数字
        if (path.size() == k) {
            if (sum == n) {
                result.push_back(path);
            }
            return;
        }
        for(int i = start; i <= 9; ++i) {
            if (sum + i > n) break;  // 剪枝,后面更大直接不用试
            path.push_back(i);
            backtrack(i = 1, k, n, sum + i);
            path.pop_back();  // 回溯
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        result.clear();
        path.clear();
        backtrack(1, k, n, 0);
        return result;
    }
};