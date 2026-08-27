// 练习                                         轮转数组
//                           给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;  // 关键：k超过数组长度时取模
        reverse(nums.begin(), nums.end());  // 整体反转
        reverse(nums.begin(), nums.begin() + k);  // 前k个反转
        reverse(nums.begin() + k, nums.end());  //后面剩下的反转
    }
};