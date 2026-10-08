#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        // 注意！乘积会溢出int，dp用long long
        vector<long long> dp(n);
        dp[0] = 1;
        vector<int> idx(k, 0);  // k个指针全部初始化为0

        for (int i = 1; i < n; ++i) {
            long long min_val = LLONG_MAX;
            // 第一轮循环：找出本轮所有候选里面最小值
            for (int j = 0; j < k; j++) {
                min_val = min(min_val, dp[idx[j]] * primes[j]);
            }
            dp[i] = min_val;

            // 第二轮循环！把所有等于min_val的指针往后移，不要break!！
            for (int j = 0; j < k; j++) {
                if (dp[idx[j]] * primes[j] == min_val) {
                    idx[j]++;
                }
            }
        }
        return (int)dp[n-1];
    }
};