#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArithemticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        vector<int> dp(n, 0);
        int ans = 0;
        for (int i = 2; i < n; i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                dp[i] = dp[i-1] + 1;
            } else {
                dp[i] = 0;
            }
            ans += dp[i];
        }
        return ans;
    }
};