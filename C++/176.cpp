#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long sum =0, f0 = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            f0 += (long long)i * nums[i];
        }
        long long ans = f0;
        long long cur = f0;
        // 依次计算 F(1),F(2)...F(n-1)
        for(int k = 1; k < n; k++) {
            // 减掉的是 nums[n-k]
            cur = cur + sum - (long long)n * nums[n - k];
            if (cur > ans) ans = cur;
        }
        return ans;
    }
};