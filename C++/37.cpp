// 练习                                    插入区间
//                                      给你一个 无重叠的 ，按照区间起始端点排序的区间列表 intervals，其中 intervals[i] = [starti, endi] 表示第 i 个区间的开始和结束，并且 intervals 按照 starti 升序排列。同样给定一个区间 newInterval = [start, end] 表示另一个区间的开始和结束。
//                                      在 intervals 中插入区间 newInterval，使得 intervals 依然按照 starti 升序排列，且区间之间不重叠（如果有必要的话，可以合并区间）。
//                                      返回插入之后的 intervals。
//                                      注意 你不需要原地修改 intervals。你可以创建一个新数组然后返回它。



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