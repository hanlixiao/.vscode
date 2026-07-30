// 练习                                             分割回文串
//                                       给你一个字符串 s，请你将 s 分割成一些 子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> res;  // 存放所有结果
    vector<string> path;  // 当前正在搜索的分割方案

    // 判断子串 s[1..r] 是否回文
    bool isPalindrome(string &s, int l, int r) {
        while(l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    // start：当前开始分割的下标
    void backtrack(string &s, int start) {
        // 递归终止：分割倒字符串末尾，找到一组方案
        if (start == s.size()) {
            res.push_back(path);
            return;
        }

        // end尝试所有分割终点:[start,end]作为一段
        for (int end = start; end < s.size(); ++end) {
            if (isPalindrome(s, start, end)) {
                // 选择：截取回文子串加入路径
                path.push_back(s.substr(start, end - start + 1));
                // 递归:下一轮从 end+1 开始分割
                backtrack(s, end + 1);
                // 回溯：撤销选择
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return res;
    }
};