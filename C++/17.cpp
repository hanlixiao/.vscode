// 练习                          两数相除
//                          给你两个整数，被除数 dividend 和除数 divisor。将两数相除，要求 不使用 乘法、除法和取余运算。
//              整数除法应该向零截断，也就是截去（truncate）其小数部分。例如，8.345 将被截断为 8 ，-2.7335 将被截断至 -2 。
//             返回被除数 dividend 除以除数 divisor 得到的 商 。



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