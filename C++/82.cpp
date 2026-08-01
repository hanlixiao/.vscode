#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int curTank = 0;
        int total = 0;
        int start = 0;

        for (int i = 0; i < n; ++i) {
            int diff = gas[i] - cost[i];
            curTank += diff;
            total += diff;

            // 当前油量不足，[start,i]全部作废，起点跳到i+1
            if (curTank < 0) {
                start = i + 1;
                curTank = 0;
            }
        }
        // 总盈亏>=0才有解
        return total >= 0 ? start : -1;
    }
};