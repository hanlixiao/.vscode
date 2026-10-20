// 练习                                                 统计各位数字都不同的数字个数
//                                         给你一个整数 n ，统计并返回各位数字都不同的数字 x 的个数，其中 0 <= x < 10n 。




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNumberWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;
        int product = 9;
        int res = 10;
        // 
        for (int i = 2; i <= n; i++) {
            product *= (10 - i + 1);
            res += product;
        }
        return res;
    }
};