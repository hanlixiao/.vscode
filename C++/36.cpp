// 练习                              合并区间
//                             以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 1．按区间的左端点排序
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        for (const auto& interval : intervals) {
            // 如果结果为空，或者当前区间的左端点>结果中最后一个区间的右端点
            // 说明不重叠，直接加入结果
            if (result.empty() || result.back()[1] < interval[0]) {
                result.push_back(interval);
            } else {
                // 否则说明重叠，更新结果中最后一个区间的右端点
                // 取最大值是为了处理[1，5]和[2，3]这种情况，合并后应为[1，5]
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }

        return result;
    }
};