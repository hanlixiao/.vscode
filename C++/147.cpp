// 练习                                                最大单词长度乘积
//                                   给你一个字符串数组 words ，找出并返回 length(words[i]) * length(words[j]) 的最大值，并且这两个单词不含有公共字母。如果不存在这样的两个单词，返回 0 。




#include <bits/stdc++.h>
using namespace std;

class Soluiton {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> mask(n, 0);
        // 预处理每一个单词的位掩码
        for (int i = 0; i < n; ++i) {
            for (char ch : words[i]) {
                int bit = ch - 'a';
                mask[i] |= (1 << bit);
            }
        }
        int ans = 0;
        // 枚举两两组合
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((mask[i] & mask[j]) == 0) {
                    int cur = words[i].size() * words[j].size();
                    if (cur > ans) ans = cur;
                }
            }
        }
        return ans;
    }
};