// 练习                           下一个排列
//                           给定一个整数数组 nums，它代表一个排列（比如 [1,2,3]）。
//                           字典序的规则，和我们查字典的顺序是一样的：
//                           [1,2,3] < [1,3,2] < [2,1,3] < [2,3,1] < [3,1,2] < [3,2,1]
//                           如果它已经是字典序里最大的排列（比如 [3,2,1]），就把它改成最小的排列（升序 [1,2,3]）



#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    void nextPermutation(vector<int>& nums)
    {
        int n = nums.size();
        int i = n -2;

        // 从右往左找第一个 nums[i]<nums[i+1的位置
        while (i >= 0 && nums[i] >= nums[i+1])
        {
            i--;
        }

        if (i >= 0)
        {
            // 从右往左找第一个比 nums[i]大的数
            int j = n - 1;
            while (nums[j] <= nums[i])
            {
                j--;
            }
            // 交换nums[i]和 nums[j]
            swap(nums[i], nums[j]);
        }

        // 反转 i 之后的所有元素
        reverse(nums.begin() + i + 1, nums.end());
    }

};