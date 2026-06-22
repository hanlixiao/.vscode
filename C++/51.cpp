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