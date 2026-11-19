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