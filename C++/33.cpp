// 练习                   最大子数组和 
//                    给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
//                    子数组是数组中的一个连续部分。



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 初始化最大和为最小整数，防止数组全是负数时出错
        int max_sum = INT_MIN;
        int current_sum = 0;

        for (int num : nums) {
            // 1.累加当前数字
            current_sum += num;

            // 2.更新最大和（在重置之前更新，因为current_sum 可能就是最大值）
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }

            // 3．如果当前和小于0，说明前面的部分是累赘，扔掉（重置为0)
            if (current_sum < 0) {
                current_sum = 0;
            }
        }

        return max_sum;
    }
};