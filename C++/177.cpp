// 练习                                                    整数替换
//                                        给定一个正整数 n ，你可以做如下操作：
//                                        如果 n 是偶数，则用 n / 2替换 n 。
//                                        如果 n 是奇数，则可以用 n + 1或n - 1替换 n 。
//                                        返回 n 变为 1 所需的 最小替换次数 。




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