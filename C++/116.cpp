#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int robRange(vector<int>& nums, int left, int right) {
        int a = 0, b = 0;
        for (int i = left; i <= right; ++i) {
            int now = max(b, a + nums[i]);
            a = b;
            b = now;
        }
        return b;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        // 方案1：不取最后一个；方案2:不取第一个
        int res1 = robRange(nums, 0, n - 2);
        int res2 = robRange(nums, 1, n - 1);
        return max(res1, res2);
    }
};