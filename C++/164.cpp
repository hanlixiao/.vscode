// 练习                                                 猜数字大小 II
//                                           我们正在玩一个猜数游戏，游戏规则如下：
//                                           我从 1 到 n 之间选择一个数字。
//                                           你来猜我选了哪个数字。
//                                           如果你猜到正确的数字，就会 赢得游戏 。
//                                           如果你猜错了，那么我会告诉你，我选的数字比你的 更大或者更小 ，并且你需要继续猜数。
//                                           每当你猜了数字 x 并且猜错了的时候，你需要支付金额为 x 的现金。如果你花光了钱，就会 输掉游戏 。
//                                           给你一个特定的数字 n ，返回能够 确保你获胜 的最小现金数，不管我选择那个数字 。




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