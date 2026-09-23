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