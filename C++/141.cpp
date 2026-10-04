// 练习                                                 累加数
//                                      累加数 是一个字符串，组成它的数字可以形成累加序列。
//                                      一个有效的 累加序列 必须 至少 包含 3 个数。除了最开始的两个数以外，序列中的每个后续数字必须是它之前两个数字之和。
//                                      给你一个只包含数字 '0'-'9' 的字符串，编写一个算法来判断给定输入是否是 累加数 。如果是，返回 true ；否则，返回 false 。
//                                      说明：累加序列里的数，除数字 0 之外，不会 以 0 开头，所以不会出现 1, 2, 03 或者 1, 02, 3 的情况。




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        // i是第一个数的长度；j是第二个数的长度
        for (int i = 1; i <= n / 2; ++i) {
            // 前导0:第一个数字长度>1并且开头是'0
            if (i > 1 && num[0] == '0') break;
            for (int j = 1; n - i - j >= max(i, j); ++j) {
                if (j > 1 &&num[i] == '0') break;
                long long a = stoll(num.substr(0, i));
                long long b = stoll(num.substr(i, j));
                int pos = i + j;  // pos：剩余字符串开始的下标
                bool ok = true;
                long long x = a, y = b;
                while (pos < n) {
                    long long z = x + y;
                    string sz = to_string(z);
                    // 拿字符串sz和原字符串pos位置往后比对
                    if (num.substr(pos, sz.size()) != sz) {
                        ok = false;
                        break;
                    }
                    pos += sz.size();
                    x = y;
                    y = x;
                }
                // 如果刚好走到字符串末尾，说明整串匹配累加序列
                if (ok && pos == n) {
                    return true;
                }
            }
        }
        return false;
    }
};