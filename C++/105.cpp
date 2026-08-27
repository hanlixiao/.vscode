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