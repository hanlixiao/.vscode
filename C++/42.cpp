// 练习                                               最小路径和 
//                                        给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
//                                        说明：每次只能向下或者向右移动一步。



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        // 行数
        int m = grid.size();
        // 列数
        int n = grid[0].size();

        // 创建 dp 数组，大小与grid 相同
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // 1．初始化起点
        dp[0][0] = grid[0][0];
        
        // 2．初始化第一列 (只能从上往下走)
        for (int i = 1; i < m; ++i) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }

        // 3。初始化第一行 (只能从左往右走)
        for (int j = 1; j < n; ++j) {
            dp[0][j] = dp[0][j-1] +grid[0][j];
        }

        // 4.填充剩余的dp 表
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                // 取上方和左方的较小值，加上当前格子的值
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }

        // 返回右下角的值
        return dp[m-1][n-1];
    }
};