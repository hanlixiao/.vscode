// 练习                        有效的括号



#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        unordered_map<char, char> map = {{'(', ')'}, {'{', '}'}, {'[', ']'}};

        for (char c : s)
        {
            // 左括号：压入对应的右括号
            if (map.count(c))
            {
                st.push(map[c]);
            }
            else
            {
                // 右括号：栈空或不匹配则返回false
                if (st.empty() || st.top() != c)
                {
                    return false;
                }
                st.pop();
            }
        }
        // 栈必须为空
        return st.empty();
    }

};