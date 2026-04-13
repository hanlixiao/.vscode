// 练习                 字符串转换整数 (atoi)
// 空格：读入字符串并丢弃无用的前导空格（" "）
// 符号：检查下一个字符（假设还未到字符末尾）为 '-' 还是 '+'。如果两者都不存在，则假定结果为正。
// 转换：通过跳过前置零来读取该整数，直到遇到非数字字符或到达字符串的结尾。如果没有读取数字，则结果为0。
// 舍入：如果整数数超过 32 位有符号整数范围 [−231,  231 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −231 的整数应该被舍入为 −231 ，大于 231 − 1 的整数应该被舍入为 231 − 1 。
// 返回整数作为最终结果。




#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int n = s.size();
        int i = 0;
        // 跳过前导空格
        while (i < n && s[i] == ' ')
        {
            i++;
        }
        // 处理符号
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-'))
        {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        // 读取数字
        int res = 0;
        const int INT_MAX_BOUND = INT_MAX / 10;
        while (i < n && isdigit(s[i]))
        {
            int digit = s[i] - '0';
            //溢出判断：正数溢出
            if (res > INT_MAX_BOUND || (res == INT_MAX_BOUND && digit > 7))
            {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            // 负数溢出（digit为正，无需额外判断< -8， 直接使用边界）
            res = res * 10 + digit;
            i++;
        }
        return res * sign;
    }

};