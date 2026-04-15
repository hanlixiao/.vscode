// 练习                       给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，
//                           同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。
//                           注意：答案中不可以包含重复的三元组。



#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> res;
        int n = nums.size();
        // 不足三个数时直接返回
        if (n < 3) return res;

        // 排序数组
        sort(nums.begin(), nums.end());

        // 遍历固定第一个数a
        for(int i = 0; i < n; ++i)
        {
            // 剪枝：a>0时，后续和不可能为0
            if (nums[i] > 0) break;
            // 去重：跳过重复的a
            if (i > 0 && nums[i] == nums[i-1]) continue;

            // 双指针找b和c
            int left = i + 1;
            int right = n - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0)
                {
                    // 记录三元组
                    res.push_back({nums[i], nums[left], nums[right]});
                    // 去重：跳过重复的b
                    while (left < right && nums[left] == nums[left+1]) left++;
                    // 去重：跳过重复的c
                    while (left < right && nums[right] == nums[right-1]) right--;
                    //移动指针
                    left++;
                    right--;
                }
                else if (sum < 0)
                {
                    // 和太小，左指针右移
                    left++;
                }
                else
                {
                    // 和太大，右指针左移
                    right--;
                }
            }
        }
        return res;
    }

};