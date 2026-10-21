// 练习                                                   水壶问题
//                                          有两个水壶，容量分别为 x 和 y 升。水的供应是无限的。确定是否有可能使用这两个壶准确得到 target 升。
//                                          你可以：
//                                          装满任意一个水壶
//                                          清空任意一个水壶
//                                          将水从一个水壶倒入另一个水壶，直到接水壶已满，或倒水壶已空。




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