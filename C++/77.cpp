// 练习                                      最长连续序列
//                              给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
//                              请你设计并实现时间复杂度为 O(n) 的算法解决此问题。




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        // 全部存入哈希集合
        for (int num : nums) {
            st.insert(num);
        }
        int maxLen = 0;
        for (int x : st) {
            // x-1不存在，说明x是连续序列起点
            if (!st.count(x - 1)) {
                int cur = x;
                int curLen = 1;
                // 向后延伸连续数字
                while (st.count(cur + 1)) {
                    cur++;
                    curLen++;
                }
                maxLen = max(maxLen, curLen);
            }
        }
        return maxLen;
    }
};