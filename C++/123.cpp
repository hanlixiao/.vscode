// 练习                                                   多数元素 II
//                                          给定一个大小为 n 的整数数组，找出其中所有出现超过 ⌊n / 3⌋ 次的元素。




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1, cand2;
        int cnt1 = 0, cnt2 = 0;
        // 第一轮摩尔投票，选出候选
        for (int x : nums) {
            if (x == cand1) {
                cnt1++;
            } else if (x == cand2) {
                cnt2++;
            } else if (cnt1 == 0) {
                cand1 = x;
                cnt1 = 1;
            } else if (cnt2 == 0) {
                cand2 = x;
                cnt2 = 1;
            } else {
                // x和两个候选都不一样，抵消一组
                cnt1--;
                cnt2--;
            }
        }
        // 第二轮校验候选的真实次数
        cnt1 = 0, cnt2 = 0;
        for (int x : nums) {
            if (x == cand1) cnt1++;
            else if (x == cand2) cnt2++;
        }
        vector<int> res;
        int n = nums.size();
        if (cnt1 > n / 3) res.push_back(cand1);
        if (cnt2 > n / 3) res.push_back(cand2);
        return res;
    }
};