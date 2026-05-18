// 练习                                  跳跃游戏 II
//                              给定一个长度为 n 的 0 索引整数数组 nums。初始位置在下标 0。
//                              每个元素 nums[i] 表示从索引 i 向后跳转的最大长度。换句话说，如果你在索引 i 处，你可以跳转到任意 (i + j) 处：
//                              0 <= j <= nums[i] 且
//                              i + j < n
//                              返回到达 n - 1 的最小跳跃次数。测试用例保证可以到达 n - 1。



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        // 只有一个元素，不需要跳
        if (nums.size() == 1) return 0;
    

        // 跳跃次数
        int jumps = 0;
        // 当前覆盖的最远距离下标
        int cur_distance = 0;
        // 下一步覆盖的最远距离下标
        int next_distance = 0;

        // 注意是 size - 1，因为不需要在最后一个元素起跳
        for (int i = 0; i < nums.size() - 1; i++) {
            // 更新下一步能跳到的最远距离
            next_distance = max(next_distance, i + nums[i]);

            // 如果走到了当前覆盖范围的边界
            if (i == cur_distance) {
                // 必须跳下一步了
                jumps++;
                // 更新当前覆盖范围
                cur_distance = next_distance;

                // 优化：如果更新后的范围已经覆盖了终点，可以提前结束
                if (cur_distance >= nums.size() - 1) {
                    break;
                }
            }
        }
        return jumps;
    }
};