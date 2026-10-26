#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // len是区间长度，len=1的时候dp已经是0，从len=2开始
        for (int len = 2; len <= n; len++) {
            // 1 是区间左端点，r是右端点
            for (int l = 1; l + len - 1 <= n; l++) {
                int r = l + len - 1;
                dp[l][r] = INT_MAX;
                // 枚举这个区间里猜x
                for (int x = l; x <= r; x++) {
                    int cost = x + max(dp[l][x-1], dp[x+1][r]);
                    if (cost < dp[l][r]) {
                        dp[l][r] = cost;
                    }
                }
            }
        }
        return dp[1][n];
    }
};