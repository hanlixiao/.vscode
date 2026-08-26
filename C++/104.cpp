#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen;
        unordered_set<string> res;
        int n = s.size();
        // i最多到n-10，不然子串不足10个字符
        for (int i = 0; i <= n - 10; ++i) {
            string sub = s.substr(i, 10);
            if (seen.count(sub)) {
                res.insert(sub);
            } else {
                seen.insert(sub);
            }
        }
        // 转成vector返回
        return vector<string>(res.begin(), res.end());
    }
};