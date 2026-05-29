#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int n = intervals.size();
        int i = 0;

        // 1．将所有在newInterval左侧且不重叠的区间加入结果
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }

        // 2．合并所有重叠的区间
        while (i < n && intervals[i][0] <= newInterval[1]) {
            // 更新newInterval的边界
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        // 将合并后的newInterval加入结果
        result.push_back(newInterval);

        // 3．将剩余在右侧的区间加入结果
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};