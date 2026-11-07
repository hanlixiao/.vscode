// 练习                                            旋转函数
//                                     给定一个长度为 n 的整数数组 nums 。
//                                     假设 arrk 是数组 nums 顺时针旋转 k 个位置后的数组，我们定义 nums 的 旋转函数  F 为：
//                                     F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1]
//                                     返回 F(0), F(1), ..., F(n-1)中的最大值 。
//                                     生成的测试用例让答案符合 32 位 整数。




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