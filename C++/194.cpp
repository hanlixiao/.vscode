// 练习                                                        寻找右区间
//                                               给你一个区间数组 intervals ，其中 intervals[i] = [starti, endi] ，且每个 starti 都 不同 。
//                                               区间 i 的 右侧区间 是满足 startj >= endi，且 startj 最小 的区间 j。注意 i 可能等于 j 。
//                                               返回一个由每个区间 i 对应的 右侧区间 下标组成的数组。如果某个区间 i 不存在对应的 右侧区间 ，则下标 i 处的值设为 -1 。




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        // pair:(start,原下标)
        vector<pair<int, int>> starts;
        for (int i = 0; i < n; i++) {
            starts.emplace_back(intervals[i][0], i);
        }
        // 按start升序
        sort(starts.begin(), starts.end());

        // 单独拿出所有start值，用来二分
        vector<int> startVals;
        for (auto &p : starts) startVals.push_back(p.first);
        
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int target = intervals[i][1];
            // lower_bound:第一个 >= target 的元素
            auto it = lower_bound(startVals.begin(), startVals.end(), target);
            if (it == startVals.end()) {
                res[i] = -1;
            } else {
                int pos = it - startVals.begin();
                res[i] = starts[pos].second;
            }
        }
        return res;
    }
};