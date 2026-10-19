#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 1.统计频次
        unordered_map<int, int> cnt;
        for(int x : nums) cnt[x]++;

        // 小根堆：pair<频次，数值>，默认优先队列是大根堆，greater变成小根堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for(auto &p : cnt) {
            int num = p.first;
            int freq = p.second;
            if (minHeap.size() < k) {
                minHeap.push({freq, num});
            } else {
                if (freq > minHeap.top().first) {
                    minHeap.pop();
                    minHeap.push({freq, num});
                }
            }
        }
        // 取出堆中元素
        vector<int> res;
        while (!minHeap.empty()) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return res;
    }
};