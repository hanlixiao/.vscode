#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;  // 空串基准
        // 初始化第一个字符
        if (s[0] != '0') dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            // 情况1：单独取当前一位
            char cur = s[i - 1];
            if (cur != '0') {
                dp[i] += dp[i - 1];
            }
            // 情况2：取末尾两位
            char pre = s[i - 2];
            int two = (pre - '0') * 10 + (cur - '0');
            if (two >= 10 && two <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};