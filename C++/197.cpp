// 练习                                                            数组中重复的数据
//                                                       给你一个长度为 n 的整数数组 nums ，其中 nums 的所有整数都在范围 [1, n] 内，且每个整数出现 最多两次 。请你找出所有出现 两次 的整数，并以数组形式返回。
//                                                       你必须设计并实现一个时间复杂度为 O(n) 且仅使用常量额外空间（不包括存储输出所需的空间）的算法解决此问题。




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