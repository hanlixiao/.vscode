#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;
            // 三数相同，无法区分有序段，左边界右移缩小范围
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                continue;
            } 
            //左半段有序
            if (nums[left] <= nums[mid]) {
                if (target >= nums[left] && target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            }
            // 右半段有序
            else {
                if (target > nums[mid] && target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            }
        }
        return false;
    }
};