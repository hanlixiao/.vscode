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