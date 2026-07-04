// 练习                                                         交错字符串
//                                            给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。
//                                            两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空 子字符串：
//                                            s = s1 + s2 + ... + sn
//                                            t = t1 + t2 + ... + tm
//                                            |n - m| <= 1
//                                            交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 + ...
//                                            注意：a + b 意味着字符串 a 和 b 连接。




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if (n1 + n2 != n3) return false;
        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
        dp[0][0] = true;
        // 初始化只取s1
        for (int i = 1; i <= n1; ++i) {
            dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
        }
        // 初始化只取s2
        for (int j = 1; j <= n2; ++j) {
            dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
        }
        // 递推填表
        for (int i =1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                char c = s3[i + j - 1];
                bool from1 = dp[i - 1][j] && (s1[i - 1] == c);
                bool from2 = dp[i][j - 1] && (s2[j - 1] == c);
                dp[i][j] = from1 || from2;
            }
        }
        return dp[n1][n2];
    }
};