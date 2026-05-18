#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        // 
        if (nums.size() == 1) return 0;
    

        // 
        int jumps = 0;
        // 
        int cur_distance = 0;
        // 
        int next_distance = 0;

        // 
        for (int i = 0; i < nums.size() - 1; i++) {
            // 
            next_distance = max(next_distance, i + nums[i]);

            // 
            if (i == cur_distance) {
                // 
                jumps++;
                // 
                cur_distance = next_distance;

                // 
                if (cur_distance >= nums.size() - 1) {
                    break;
                }
            }
        }
        return jumps;
    }
};