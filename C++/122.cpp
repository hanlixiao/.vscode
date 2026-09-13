// 练习                                           基本计算器 II
//                               给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。
//                               整数除法仅保留整数部分。
//                               你可以假设给定的表达式总是有效的。所有中间结果将在 [-231, 231 - 1] 的范围内。
//                               注意：不允许使用任何将字符串作为数学表达式计算的内置函数，比如 eval() 。




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        char op = '+';  // 记录上一个运算符
        int num = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            // 遇到运算符或者 到最后一个字符，就要计算
            if ((!isdigit(c) && c != ' ') || i == n - 1) {
                if (op == '+') st.push(num);
                else if (op == '-') st.push(-num);
                else if (op == '*') {
                    int top = st.top();
                    st.pop();
                    st.push(top * num);
                }
                else if (op == '/') {
                    int top = st.top();
                    st.pop();
                    st.push(top / num);
                }
                op = c;  // 更新运算符
                num = 0;
            }
        }
        // 栈内全部相加
        int res = 0;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};