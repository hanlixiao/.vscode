// 练习                                            比较版本号
//                                 给你两个 版本号字符串 version1 和 version2 ，请你比较它们。版本号由被点 '.' 分开的修订号组成。修订号的值 是它 转换为整数 并忽略前导零。
//                                 比较版本号时，请按 从左到右的顺序 依次比较它们的修订号。如果其中一个版本字符串的修订号较少，则将缺失的修订号视为 0。
//                                 返回规则如下：
//                                 如果 version1 < version2 返回 -1，
//                                 如果 version1 > version2 返回 1，
//                                 除此之外返回 0。




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int n1 = version1.size(), n2 = version2.size();

        while (i < n1 || j < n2) {
            int num1 = 0, num2 = 0;
            // 提取version1 当前修订号
            while (i < n1 && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }
            // 跳过'.'
            i++;
            // 提取 version2 当前修订号
            while (j < n2 && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }
            // 跳过'.'
            j++;

            if (num1 > num2) return 1;
            if (num1 < num2) return -1;
        }
        return 0;
    }
};