// 练习                                                         替换后的最长重复字符
//                                               给你一个字符串 s 和一个整数 k 。你可以选择字符串中的任一字符，并将其更改为任何其他大写英文字符。该操作最多可执行 k 次。
//                                               在执行上述操作后，返回 包含相同字母的最长子字符串的长度。




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int charachterReplacement(string s, int k) {
        vector<int> cnt(26, 0);
        int left = 0;
        int maxCnt = 0;  // 窗口里出现最多的字符次数
        int res = 0;
        for (int right = 0; right < s.size(); right++) {
            int idx = s[right] - 'A';
            cnt[idx]++;
            maxCnt = max(maxCnt, cnt[idx]);

            // 窗口长度 -最多字符数 >k，替换不够，左边界右移
            while (right - left + 1 - maxCnt > k) {
                cnt[s[left] - 'A']--;
                left++;
            }
            // 更新最大窗口长度
            res = max(res, right - left + 1);
        }
        return res;
    }
};