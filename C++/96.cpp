#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid + 1]) {
                // 上升，峰值在右边
                left = mid + 1;
            } else {
                // 下降，mid有可能是峰值
                right = mid;
            }
        }
        return left;
    }
};