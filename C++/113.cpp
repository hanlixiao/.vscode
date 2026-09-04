#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSuArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int sum = 0;
        int res = INT_MAX;

        for (int right = 0; right < n; right++) {
            sum += nums[right];
            // 满足条件，不断收紧左边界
            while (sum >= target) {
                res = min(res, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};