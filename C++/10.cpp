// 练习                       电话号码的字母组合
//                            给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
//                            给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。


#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        if (digits.empty()) return res;

        // 数字到字母的映射（索引对应数字）
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        string path;
        backtrack(digits, 0, path, res, mapping);
        return res;
    }

private:
    void backtrack(const string& digits, int index, string& path, vector<string>& res, const vector<string>& mapping)
    {
        // 终止条件：处理完所有数字
        if (index == digits.size())
        {
            res.push_back(path);
            return;
        }

        // 当前数字对应的字母表
        string letters = mapping[digits[index] - '0'];
        for (char c : letters)
        {
            // 选择
            path.push_back(c);
            // 递归
            backtrack(digits, index + 1, path, res, mapping);
            // 回溯（撤销选择）
            path.pop_back();
        }
    }

};