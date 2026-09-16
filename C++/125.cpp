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