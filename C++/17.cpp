#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        // 溢出边界特判
        if (dividend == INT_MIN && divisor == -1)
        {
            return INT_MAX;
        }

        // 处理符号
        bool positive = (dividend > 0) == (divisor > 0);
        // 转为负数处理，避免正数溢出
        long long a = llabs(dividend);
        long long b = llabs(divisor);
        long long res = 0;

        // 倍增减法：每次减去 divisor * 2^k
        while (a >= b)
        {
            long long tmp = b;
            long long cnt = 1;
            // 不断翻倍，直到超过被除数
            while (tmp << 1 <= a)
            {
                tmp <<= 1;
                cnt <<= 1;
            }
            a -= tmp;
            res += cnt;
        }
        return positive ? res : -res;
    }

};