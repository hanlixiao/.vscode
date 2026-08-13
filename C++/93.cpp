// 练习                                            乘积最大子数组
//                                    给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续 子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
//                                    测试用例的答案是一个 32-位 整数。
//                                    请注意，一个只包含一个元素的数组的乘积是这个元素的值。




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