// 练习                                                             分割等和子集
//                                                   给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。




#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        int target = sum / 2;

        vector<bool> dp(target + 1, false);
        dp[0] = true;  // 和为0一定可以(什么都不选)

        for (int x : nums) {
            // 倒序遍历，防止重复选取同一个元素
            for ( int j = target; j >= x; j--) {
                dp[j] = dp[j] || dp[j - x];
            }
        }
        return dp[target];
    }
};