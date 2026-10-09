// 练习                                                去除重复字母
//                                     给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。




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