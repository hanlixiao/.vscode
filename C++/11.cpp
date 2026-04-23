// 练习                 四数之和
//                    给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
//                    0 <= a, b, c, d < n
//                    a、b、c 和 d 互不相同
//                    nums[a] + nums[b] + nums[c] + nums[d] == target
//                    你可以按 任意顺序 返回答案 。



#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> res;
        int n = nums.size();
        // 不足4个数，直接返回空
        if (n < 4) return res;

        // 排序数组
        sort(nums.begin(), nums.end());

        // 固定第个数a
        for (int i = 0; i < n - 3; ++i)
        {
            // 剪枝：若nums[i]*4>target，后续和不可能为target
            if ((long long)nums[i] * 4 > target) break;
            // 去重：跳过重复的a
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // 固定第二个数b
            for (int j = i + 1; j < n - 2; ++j)
            {
                // 剪枝：若nums[i]+nums[j]*3 >target，后续和不可能为target
                if ((long long)nums[i] + (long long)nums[j] * 3 > target) break;
                // 去重：跳过重复的b
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // 双指针找c和d
                int left = j + 1;
                int right = n - 1;
                while (left < right)
                {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target)
                    {
                        // 记录四元组
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        // 去重：跳过重复的c
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        // 去重：跳过重复的d
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        // 移动指针
                        left++;
                        right--;
                    }
                    else if (sum < target)
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
        }
    }

};