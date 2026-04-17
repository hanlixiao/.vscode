// 练习                   最长公共前缀



#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        //如果传入数组为空直接返回
        if (strs.empty()) return "";
        string prefix = strs[0];

        for (int i = 1; i < strs.size(); ++i)
        {
            //不断缩短prefix，直到与当前字符串匹配
            while (strs[i].find(prefix) != 0)
            {
                prefix = prefix.substr(0, prefix.size() - 1);
                if (prefix.empty()) return "";
            }
        }
        return prefix;

    }

};