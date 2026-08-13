#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int> & nums) {
        int res = nums[0];
        int curMax = nums[0];
        int curMin = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            // 先保存旧的curMax，避免被覆盖
            int temp = curMax;
            curMax = max({nums[i], temp * nums[i], curMin * nums[i]});
            curMin = min({nums[i], temp * nums[i], curMin * nums[i]});
            // 更新全局最大值
            res = max(res, curMax);
        }
        return res;
    }
};