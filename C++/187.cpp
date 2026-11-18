// 练习                                                    从英文中重建数字
//                                                 给你一个字符串 s ，其中包含字母顺序打乱的用英文单词表示的若干数字（0-9）。按 升序 返回原始的数字。




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string originalDigits(string s) {
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;
        vector<int> cnt(10, 0);

        // 唯一特征
        cnt[0] = count['z' - 'a'];
        cnt[2] = count['w' - 'a'];
        cnt[4] = count['u' - 'a'];
        cnt[6] = count['x' - 'a'];
        cnt[8] = count['g' - 'a'];
        
        // 推导
        cnt[1] = count['0' - 'a'] - cnt[0] - cnt[2] - cnt[4];
        cnt[3] = count['h' - 'a'] - cnt[8];
        cnt[5] = count['f' - 'a'] - cnt[4];
        cnt[7] = count['s' - 'a'] - cnt[6];
        cnt[9] = count['i' - 'a'] - cnt[5] - cnt[6] - cnt[8];

        string res;
        for (int i = 0; i <= 9; ++i) {
            res += string(cnt[i], '0' + i);
        }
        return res;
    }
};