#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            // 取绝对值，因为这个位置可能已经被标记成负数
            int x = abs(nums[i]);
            int idx = x - 1;
            if (nums[idx] < 0) {
                // 已经是负数，说明x重复了
                ans.push_back(x);
            } else {
                // 第一次访问，标记为负
                nums[idx] = -nums[idx];
            }
        }
        return ans;
    }
};