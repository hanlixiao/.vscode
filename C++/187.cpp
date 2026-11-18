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