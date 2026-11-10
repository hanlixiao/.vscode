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
        // 
        long long num = start + (n - 1) / len;
        // 
        int idx = (n - 1) % len;
        string s = to_string(num);
        return s[idx] - '0';
    }
};