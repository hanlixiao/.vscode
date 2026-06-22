// 练习                                                删除有序数组中的重复项 II
//                                     给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使得出现次数超过两次的元素只出现两次 ，返回删除后数组的新长度。
//                                     不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        int slow = 1;
        for (int fast = 2; fast < n; fast++) {
            // 和slow前一位对比，相同则代表当前已经出现2次，跳过
            if (nums[fast] != nums[slow - 1]) {
                slow++;
                nums[slow] =nums[fast];
            }
        }
        return slow + 1;
    }
};