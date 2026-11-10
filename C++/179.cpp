// 练习                                                    第 N 位数字
//                                                  给你一个整数 n ，请你在无限的整数序列 [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...] 中找出并返回第 n 位上的数字。




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        long long len = 1;  // 当前数字的位数
        long long start = 1;  // 当前段第一个数
        long long count = 9;  // 当前段数字总个数

        while (n > len * count) {
            n -= len * count;
            len++;
            start *= 10;
            count *= 10;
        }
        // 找到目标数字
        long long num = start + (n - 1) / len;
        // 数字里的下标
        int idx = (n - 1) % len;
        string s = to_string(num);
        return s[idx] - '0';
    }
};