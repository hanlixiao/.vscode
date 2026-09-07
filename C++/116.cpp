// 练习                                        打家劫舍 II
//                                 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
//                                 给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。




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