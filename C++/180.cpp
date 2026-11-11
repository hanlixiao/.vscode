#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;  // 充当单调栈
        for (char c : num) {
            // 栈不为空、栈顶更大、还有删除名额
            while (!st.empty() && st.back() > c && k > 0) {
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }
        // 剩下k，从后面删
        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }
        // 去掉前导0
        int start = 0;
        while (start < st.size() && st[start] == '0') {
            start++;
        }
        string res = st.substr(start);
        return res.empty() ? "0" : res;
    }
};