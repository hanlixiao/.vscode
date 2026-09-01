#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; (long long)i * i < n; ++i) {
            if (isPrime[i]) {
                // 从 i*i 开始标记所有倍数
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        // 统计true的数量
        int cnt = 0;
        for (bool flag : isPrime) {
            if (flag) cnt++;
        }
        return cnt;
    }
};