#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        // 按右端点升序排序
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 1;  // 最多能保留的区间数量，至少选第一个
        int last_end = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {
            int cur_start = intervals[i][0];
            // 当前区间起点>=上一个终点，不重叠，可以选
            if (cur_start >= last_end) {
                count++;
                last_end = intervals[i][1];
            }
            // 重叠了：跳过这个区间（相当于把它删掉）
        }
        // 需要移除的 = 总数 - 最多保留数
        return intervals.size() - count;
    }
};