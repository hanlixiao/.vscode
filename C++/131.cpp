// 练习                                              只出现一次的数字 III
//                                         给你一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。
//                                         你必须设计并实现线性时间复杂度的算法且仅使用常量额外空间来解决此问题。




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xor_all = 0;
        for (int x : nums) {
            xor_all ^= x;
        }
        // 取出最右边的1；注意！这里要用long long防止负数溢出！
        long long mask = xor_all & (-xor_all);
        int a = 0, b = 0;
        for (int x : nums) {
            if (x & mask) {
                a ^= x;
            } else {
                b ^= x;
            }
        }
        return {a, b};
    }
};