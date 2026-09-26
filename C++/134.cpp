// 练习                                         H 指数 II
//                                  给你一个整数数组 citations ，其中 citations[i] 表示研究者的第 i 篇论文被引用的次数，citations 已经按照 非降序排列 。计算并返回该研究者的 h 指数。
//                                  h 指数的定义：h 代表“高引用次数”（high citations），一名科研人员的 h 指数是指他（她）的 （n 篇论文中）至少 有 h 篇论文分别被引用了至少 h 次。
//                                  请你设计并实现对数时间复杂度的算法解决此问题。




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n - 1;
        int ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            int h_candidate = n - mid;
            if (citations[mid] >= h_candidate) {
                ans = h_candidate;
                right = mid - 1;  // 往左，试图找更大h
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};