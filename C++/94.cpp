// 练习                                              寻找旋转排序数组中的最小值



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;  // 防溢出写法
            if (nums[mid] > nums[right]) {
                // 最小值在右半边
                left = mid + 1;
            } else {
                // 最小值在左半边（包含mid）
                right = mid;
            }
        }
        // 最终left == right，就是最小值下标
        return nums[left];
    }
};