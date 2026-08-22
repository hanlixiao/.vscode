// 练习                                   阶乘后的零
//                                 给定一个整数 n ，返回 n! 结果中尾随零的数量。
//                                 提示 n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;
        while (n > 0) {
            n /= 5;
            cnt += n;
        }
        return cnt;
    }
};