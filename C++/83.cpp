#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int res = 0;
    // 遍历32个二进制位
    for (int bit = 0; bit < 32; bit++) {
        int cnt = 0;
        for (int x : nums) {
            if (x >> bit & 1) cnt++;
        }
        if (cnt % 3 != 0) {
            res |= (1 << bit);
        }
    }
    return res;
}