#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        // 两个数不相等，说明低位存在不一样的bit，要消掉
        while (left != right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }
        // 把公共前缀左移补回shift个0
        return left << shift;
    }
};