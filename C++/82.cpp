// 练习                                           加油站
//                                 在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
//                                 你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。
//                                 给定两个整数数组 gas 和 cost ，如果你可以按顺序绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1 。如果存在解，则 保证 它是 唯一 的。




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