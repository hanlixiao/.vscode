// 练习                                                     至少有 K 个重复字符的最长子串
//                                              给你一个字符串 s 和一个整数 k ，请你找出 s 中的最长子串， 要求该子串中的每一字符出现次数都不少于 k 。返回这一子串的长度。
//                                              如果不存在这样的子字符串，则返回 0。




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int long gestSubstring(string s, int k) {
        return dfs(s, 0, s.size() - 1, k);
    }

    int dfs(string &s, int l, int r, int k) {
        if (l > r) return 0;
        // 统计当前区间字符频次
        int cnt[26] = {0};
        for (int i = l; i <= r; i++) cnt[s[i]-'a']++;
        // 找分割点:频次小于k的字符
        int split = -1;
        for (int i = l; i <= r; i++) {
            if (cnt[s[i]-'a'] < k) {
                split= i;
                break;
            }
        }
        // 没有分割点，全部满足条件
        if (split == -1) return r - l + 1;
        // 从split切开，左右递归
        return max(dfs(s, l, split-1, k), dfs(s, split+1, r, k));
    }
};