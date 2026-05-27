// 练习                         跳跃游戏
//                      给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你在该位置可以跳跃的最大长度。
//                      判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        // 当前能到达的最远下标
        int max_reach = 0;

        for (int i = 0; i < n; ++i) {
            // 如果当前下标超过了最远能到达的距离，说明跳不过去
            if (i > max_reach) {
                return false;
            }

            // 更新最远能到达的距离
            max_reach = max(max_reach, i + nums[i]);

            //如果最远距离已经覆盖终点，直接返回 true
            if (max_reach >= n - 1) {
                return true;
            }
        }

        return true;
    }
};