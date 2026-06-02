#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // 创建一个 m x n 的二维数组，初始化为0
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // 1．初始化第一列：只有一种走法（一直向下）
        for (int i = 0; i < m; ++i) {
            dp[i][0] = 1;
        }

        // 2．初始化第一行：只有一种走法（一直向右)
        for (int j = 0; j < n; ++j) {
            dp[0][j] = 1;
        }

        // 3.填充剩余的格子
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                // 当前格子的路径数= 上方格子的路径数+左方格子的路径数
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        // 返回右下角的结果
        return dp[m - 1][n - 1];
    }
};