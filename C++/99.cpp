#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // 处理正负号，用long long防止溢出
        long long num = numerator;
        long long den = denominator;
        if (num == 0) return "0";  // 分子为0直接返回

        string res;
        // 判断正负
        if ((num < 0) ^ (den < 0)) res += "-";
        num = abs(num);
        den = abs(den);

        // 整数部分
        res += to_string(num / den);
        long long rem = num % den;
        if (rem == 0) return res;  // 没有小数,直接返回

        res += ".";
        unordered_map<long long, int> rem_pos;  // key:余数,value:在res中的下标

        while (rem != 0) {
            if (rem_pos.find(rem) != rem_pos.end()) {
                // 余数重复，找到循环起点，插入左括号
                res.insert(rem_pos[rem], "(");
                res += ")";
                break;
            }
            rem_pos[rem] = res.size();  // 记录当前余数对应的位置
            rem *= 10;
            res += to_string(rem / den);
            rem = rem % den;
        }
        return res;
    }
};