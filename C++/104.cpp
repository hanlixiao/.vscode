// 练习                                                重复的DNA序列
//                                DNA序列 由一系列核苷酸组成，缩写为 'A', 'C', 'G' 和 'T'.。
//                                例如，"ACGAATTCCG" 是一个 DNA序列 。
//                                在研究 DNA 时，识别 DNA 中的重复序列非常有用。
//                                给定一个表示 DNA序列 的字符串 s ，返回所有在 DNA 分子中出现不止一次的 长度为 10 的序列(子字符串)。你可以按 任意顺序 返回答案。




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen;
        unordered_set<string> res;
        int n = s.size();
        // i最多到n-10，不然子串不足10个字符
        for (int i = 0; i <= n - 10; ++i) {
            string sub = s.substr(i, 10);
            if (seen.count(sub)) {
                res.insert(sub);
            } else {
                seen.insert(sub);
            }
        }
        // 转成vector返回
        return vector<string>(res.begin(), res.end());
    }
};