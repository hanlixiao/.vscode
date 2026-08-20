// 练习                                           分数到小数
//                                  给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以 字符串形式返回小数 。
//                                  如果小数部分为循环小数，则将循环的部分括在括号内。
//                                  如果存在多个答案，只需返回 任意一个 。
//                                  对于所有给定的输入，保证 答案字符串的长度小于 104 。
//                                  注意，如果分数可以表示为有限长度的字符串，则 必须 返回它。




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