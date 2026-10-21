#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 欧几里得算法求最大公约数
    int gcd (int a, int b) {
        while (b != 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }

    bool canMeasureWater(int x, int y, int target) {
        // 条件1：总量不能超过两壶容量和；条件2：target是最大公约数倍数
        if (x + y < target) return false;
        return target & gcd(x, y) == 0;
    }
};