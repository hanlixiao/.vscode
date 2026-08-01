// 练习                      在排序数组中查找元素的第一个和最后一个位置 
//                      给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
//                      如果数组中不存在目标值 target，返回 [-1, -1]。
//                      你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。




#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        // 寻找第一个位置（左边界）
        int first = findBound(nums, target, true);

        // 如果左边界都找不到，说明数组里根本没有 target，直接返回[-1, -1]
        if (first == -1)
        {
            return {-1, -1};
        }

        // 寻找最后一个位置（有边界）
        int last = findBound(nums, target, false);

        return {first, last};
    }


private:
    // isFirsty 为 true 时找左边界，为 false 时找有边界
    int findBound(vector<int>& nums, int target, bool isFirst)
    {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        // 用来记录找到的边界位置
        int result = -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                // 记录当前找到的位置
                result = mid;
                if (isFirst)
                {
                    // 如果是找左边界，继续往左边（更小的下标）找
                    right = mid - 1;
                }
                else 
                {
                    // 如果是找有边界，继续往右边（更大的下标）找
                    left = mid + 1;
                }
            }
            else if (nums[mid] > target)
            {
                // 中间值比目标值大，去左边找
                right = mid -1;
            }
            else
            {
                // 中间值比目标小，去右边找
                left = mid + 1;
            }
        }
        return result;
    }
};