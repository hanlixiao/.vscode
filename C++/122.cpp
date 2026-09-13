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