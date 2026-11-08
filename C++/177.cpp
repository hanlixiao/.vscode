#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
        long long x = n;  // 防止n=2147483647时n+1溢出
        int step = 0;
        while (x != 1) {
            if (x % 2 == 0) {
                x /= 2;
            } else {
                if (x == 3 || x % 4 == 1) x--;
                else x++;
            }
            step++;
        }
        return step;
    }
};