#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        int n = nums.size();
        // i:结果数组下标，1:左半指针，r:右半指针
        int l = (n - 1) / 2;
        int r = n - 1;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                // 偶数位0,2,4放小数（从后往前拿左半）
                nums[i] = tmp[l--];
            } else {
                // 奇数位 1,3,5 放大数（从后往前拿右半）
                nums[i] = tmp[r--];
            }
        }
    }
};