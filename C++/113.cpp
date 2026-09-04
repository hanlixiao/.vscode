// 练习                                              长度最小的子数组
//                                       给定一个含有 n 个正整数的数组和一个正整数 target 。
//                                       找出该数组中满足其总和大于等于 target 的长度最小的 子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSuArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int sum = 0;
        int res = INT_MAX;

        for (int right = 0; right < n; right++) {
            sum += nums[right];
            // 满足条件，不断收紧左边界
            while (sum >= target) {
                res = min(res, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};