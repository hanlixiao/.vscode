//练习               整数反转
//                   如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。
//                   假设环境不允许存储 64 位整数（有符号或无符号）。



#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        // 32位有符号整数的边界
        const int INT_MAX_BOUND = INT_MAX / 10;
        const int INT_MIN_BOUND = INT_MIN / 10;

        int res = 0;
        while (x != 0)
        {
            // 取最后一位（负数取模结果为负，无需单独处理符号）
            int digit = x % 10;

            // 溢出判断
            if (res > INT_MAX_BOUND || (res == INT_MAX_BOUND && digit > 7))
            {
                return 0;
            }
            if (res < INT_MIN_BOUND || (res == INT_MIN_BOUND && digit < -8))
            {
                return 0;
            }

            // 拼接
            res = res * 10 + digit;
            // 去掉最后一位
            x /= 10;
        }
        return res;
    }

};