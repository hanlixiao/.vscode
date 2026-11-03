// 练习                                                        消除游戏
//                                            列表 arr 由在范围 [1, n] 中的所有整数组成，并按严格递增排序。请你对 arr 应用下述算法：
//                                            从左到右，删除第一个数字，然后每隔一个数字删除一个，直到到达列表末尾。
//                                            重复上面的步骤，但这次是从右到左。也就是，删除最右侧的数字，然后剩下的数字每隔一个删除一个。
//                                            不断重复这两步，从左到右和从右到左交替进行，直到只剩下一个数字。
//                                            给你整数 n ，返回 arr 最后剩下的数字。




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