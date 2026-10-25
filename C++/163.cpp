#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // 小根堆：{sum,i,j}
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

        int n1 = nums1.size(), n2 = nums2.size();
        // 初始化:nums1[i] 搭配 nums2[0],最多k个
        for (int i = 0; i < min(k, n1); ++i) {
            pq.push({nums1[i] + nums2[0], i, 0});
        }

        vector<vector<int>> res;
        while (k-- && !pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int i = cur[1], j = cur[2];
            res.push_back({nums1[i], nums2[j]});
            // j还能往后走，压入(i,j+1)
            if (j + 1 < n2) {
                pq.push({nums1[i] + nums2[j+1], i, j+1});
            }
        }
        return res;
    }
};