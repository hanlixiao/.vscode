#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        int head = 1;
        int step = 1;
        int cnt = n;
        bool left = true;
        while (cnt > 1) {
            if (left) {
                // 左到右删，head一定右移step
                head += step;
            } else {
                // 右到左删，只有奇数个的时候head才右移
                if (cnt % 2 == 1) {
                    head += step;
                }
            }
            cnt /= 2;
            step *= 2;
            left = !left;
        }
        return head;
    }
};