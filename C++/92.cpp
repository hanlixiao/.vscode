#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;

        // 自动按空格分割，跳过所有多余空格
        while (ss >> word) {
            words.push_back(word);
        }

        // 反转单词数组
        reverse(words.begin(), words.end());

        // 拼接结果
        string res;
        for (int i = 0; i < words.size(); ++i) {
            if (i > 0) res += " ";
            res += words[i];
        }
        return res;
    }
};