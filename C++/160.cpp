// 练习                                                  最大整除子集
//                                            给你一个由 无重复 正整数组成的集合 nums ，请你找出并返回其中最大的整除子集 answer ，子集中每一元素对 (answer[i], answer[j]) 都应当满足：
//                                            answer[i] % answer[j] == 0 ，或
//                                            answer[j] % answer[i] == 0
//                                            如果存在多个有效解子集，返回其中任何一个均可。




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> pre(n, -1);
        int maxLen = 1;
        int maxIdx = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        pre[i] = j;
                    }
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                maxIdx = i;
            }
        }
        // 回溯构造答案
        vector<int> ans;
        int cur = maxIdx;
        while (cur != -1) {
            ans.push_back(nums[cur]);
            cur = pre[cur];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};