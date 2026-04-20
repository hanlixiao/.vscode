// 练习                               最接近的三数之和
//                      给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个在 不同下标位置 的整数，使它们的和与 target 最接近。
//                      返回这三个数的和。
//                      假定每组输入只存在恰好一个解。



#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // 初始化最接近值为前三个数的和
        int res = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n; ++i)
        {
            // 剪枝：跳过重复的a
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                // 若找到完全匹配的和，直接返回
                if (sum == target) return target;
                // 更新最接近值
                if (abs(sum - target) < abs(res - target))
                {
                    res = sum;
                }
                // 移动指针
                if (sum < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        return res;

    }

};