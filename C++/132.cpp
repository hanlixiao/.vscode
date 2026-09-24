// 练习                                     丑数 II
//                               给你一个整数 n ，请你找出并返回第 n 个 丑数 。
//                               丑数 就是质因子只包含 2、3 和 5 的正整数。




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; ++i) {
            int v2 = dp[p2] * 2;
            int v3 = dp[p3] * 3;
            int v5 = dp[p5] * 5;
            dp[i] = min({v2, v3, v5});
            if (dp[i] == v2) p2++;
            if (dp[i] == v3) p3++;
            if (dp[i] == v5) p5++;
        }
        return dp[n - 1];
    }
};