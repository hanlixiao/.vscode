#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNumberWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;
        int product = 9;
        int res = 10;
        // 
        for (int i = 2; i <= n; i++) {
            product *= (10 - i + 1);
            res += product;
        }
        return res;
    }
};