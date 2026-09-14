#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1, cand2;
        int cnt1 = 0, cnt2 = 0;
        // 
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
                cnt1--;
                cnt2--;
            }
        }
        // 
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