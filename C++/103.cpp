#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        // 全部阵转字符串
        for (int x : nums) {
            strs.push_back(to_string(x));
        }
        // 自定义排序
        sort(strs.begin(), strs.end(), [](const string& a, const string& b){
            return a + b > b + a;
        });
        // 特殊情况：第一个是"0”，说明全部睹是0
        if (strs[0] == "0") return "0";

        string res;
        for (auto &s : strs) {
            res += s;
        }
        return res;
    }
};