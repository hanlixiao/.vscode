#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 排序:身高降序，身高一样k升序
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) return a[0] > b[0];
            return a[1] < b[1];
        });
        vector<vector<int>> res;
        for (auto &p : people) {
            // 插入到下标p[1]的位置
            res.insert(res.begin() + p[1], p);
        }
        return res;
    }
};