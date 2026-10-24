// 练习                                                 超级次方
//                                       你的任务是计算 ab 对 1337 取模，a 是一个正整数，b 是一个非常大的正整数且会以数组形式给出。




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // 快速幂: x^n % mod
    long long qpow(long long x, long long n, long long mod) {
        long long res = 1;
        x %= mod;
        while (n > 0) {
            if (n & 1) res = res * x % mod;
            x = x * x % mod;
            n >>= 1;
        }
        return res;
    }

public:
    int suprePow(int a, vector<int>& b) {
        const int MOD = 1337;
        long long ans = 1;
        // 从最低位（数组末尾）开始
        for (int i = b.size()-1; i >= 0; i--) {
            ans = ans * qpow(a, b[i], MOD) % MOD;
            a = qpow(a, 10, MOD);
        }
        return ans;
    }
};