// 练习                                             最大正方形
//                                     在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。




#include <bits/stdc++.h>
using namespace std;

class Soluiton {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxSide = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        // 第一行 或 第一列，最多边长1
                        dp[i][j] = 1;
                    } else {
                        // 状态转移：取上、左、左上最小值 +1
                        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    }
                    maxSide = max(maxSide, dp[i][j]);  // 更新最大边长
                }
                // matrix是'0',dp[i][j]保持0
            }
        }
        return maxSide * maxSide;
    }
};