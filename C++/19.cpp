#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        int n = nums.size();
        if (n == 0) return -1;
        if (n == 1) return nums[0] == target ? 0 : -1;

        int left = 0;
        int right = n -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }

            // 判断左半部分是否有序
            // 注意：这里必须包含等号，因为当left ==mid 时，也算作左边有序
            if (nums[left] <= nums[mid])
            {
                // 左半部分[left，mid]是有序的
                // 检查target是否在这个有序区间内
                if (nums[left] <= target && target < nums[mid])
                {
                    // target 在左边，收缩右边
                    right = mid - 1;
                }
                else
                {
                    // target 在右边，收缩左边
                    left = mid + 1;
                }
            }
            else
            {
                // 右半部分[mid，right]是有序的
                // 检查 target 是否在这个有序区间内
                if (nums[mid] < target && target <= nums[right])
                {
                    // target 在右边，收缩左边
                    left = mid + 1;
                }
                else
                {
                    // target 在左边，收缩右边
                    right = mid - 1;
                }
            }
        }
        return -1;
    }

};