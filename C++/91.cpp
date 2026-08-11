#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string s : tokens) {
            // 判断是运算符
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                int res;
                if (s == "+") res = a + b;
                else if (s == "-") res = a - b;
                else if (s == "*") res = a * b;
                else {
                    // 除法：向零截断，C++整数除法默认就是向零取整
                    res = a / b;
                }
                st.push(res);
            } else {
                // 数字转int入栈
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};