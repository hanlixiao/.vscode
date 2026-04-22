#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        if (digits.empty()) return res;


        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        string path;
        backtrack(digits, 0, path, res, mapping);
        return res;
    }

private:
    void backtrack(const string& digits, int index, string& path, vector<string>& res, const vector<string>& mapping)
    {

        if (index == digits.size())
        {
            res.push_back(path);
            return;
        }


        string letters = mapping[digits[index] - '0'];
        for (char c : letters)
        {

            path.push_back(c);

            backtrack(digits, index + 1, path, res, mapping);
            
            path.pop_back;
        }
    }

};