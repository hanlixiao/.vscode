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
                int pos = i + j;
                bool ok = true;
                long long x = a, y = b;
                while (pos < n) {
                    long long z = x + y;
                    string sz = to_string(z);
                    if (num.substr(pos, sz.size()) != sz) {
                        ok = false;
                        break;
                    }
                    pos += sz.size();
                    x = y;
                    y = x;
                }
                if (ok && pos == n) {
                    return true;
                }
            }
        }
        return false;
    }
};