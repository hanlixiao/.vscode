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