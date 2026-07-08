// 练习                                       编辑距离 
//                                   给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。
//                                   你可以对一个单词进行如下三种操作：
//                                   插入一个字符
//                                   删除一个字符
//                                   替换一个字符



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        // 创建（m+1）×（n+1）的二维数组
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // 1．初始化边界
        // word1 为空，变成word2 需要插入j个字符
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j;
        }
        // word2 为空，word1 变成空需要删除i个字符
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }

        // 2.填充DP表
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i-1] == word2[j-1]) {
                    // 字符相同，不需要操作，直接继承左上角的状态
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    // 字符不同，取三种操作的最小值+1
                    // dp[i-1][j-1]：替换
                    // dp[i-1][j]:删除（word1[i-1])
                    // dp[i][j-1]:插入（word2[j-1])
                    dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
                }
            }
        }

        // 3.返回最终结果
        return dp[m][n];
    }
};