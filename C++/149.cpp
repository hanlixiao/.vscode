#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 设一个大数，大于最大可能硬币数(amount最多全用1元硬币，amount个)
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;  // 0元需要0枚硬币

        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i) {
                    // 硬币面值不能超过当前金额
                    dp[i] = min(dp[i], dp[i-coin] + 1);
                }
            }
        }
        // 如果最后值还是大于amount，说明无法凑出
        return dp[amount] > amount ? -1 : dp[amount];
    }
};