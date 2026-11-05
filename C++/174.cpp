#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString (string s) {
        stack<pair<string, int>> st;
        string res;
        int num = 0;
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                st.push({res, num});
                res = "";
                num = 0;
            } else if (c == ']') {
                auto [prev_str, k] = st.top();
                st.pop();
                string temp;
                for (int i = 0; i < k; i++) {
                    temp += res;
                }
                res = prev_str + temp;
            } else {
                res += c;
            }
        }
        return res;
    }
};