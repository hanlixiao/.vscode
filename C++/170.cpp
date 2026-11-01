// 练习                                                        字典序排数
//                                                 给你一个整数 n ，按字典序返回范围 [1, n] 内所有整数。
//                                                 你必须设计一个时间复杂度为 O(n) 且使用 O(1) 额外空间的算法。




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        int cur = 1;
        for (int i = 0; i < n; i++) {
            res.push_back(cur);
            if (cur * 10 <= n) {
                // 往下走：*10
                cur *= 10;
            } else {
                // 不能往下，就+1，遇到末尾9要回退
                while (cur % 10 == 9 || cur + 1 > n) {
                    cur /= 10;
                }
                cur++;
            }
        }
        return res;
    }
};