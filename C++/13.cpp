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

            if (map.count(c))
            {
                st.push(map[c]);
            }
            else
            {

                if (st.empty() || st.top() != c)
                {
                    return false;
                }
                st.pop();
            }
        }

        return st.empty();
    }

};