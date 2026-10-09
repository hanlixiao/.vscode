#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26, 0);
        vector<bool> inStack(26, false);
        for (char ch : s) {
            count[ch-'a']++;
        }
        string stk;  // 直接用string充当栈

        for (char c : s) {
            count[c-'a']--;  // 先把剩余次数减1

            if (inStack[c-'a']) continue;

            // 单调栈：如果栈顶比当前字符大，并且后面还存在栈顶字符，弹出
            while(!stk.empty() && stk.back() > c && count[stk.back()-'a'] > 0) {
                inStack[stk.back()-'a'] = false;
                stk.pop_back();
            }
            stk.push_back(c);
            inStack[c-'a'] = true;
        }
        return stk;
    }
};