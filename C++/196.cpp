// 练习                                          找到字符串中所有字母异位词
//                                    给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int n = s.size(), m = p.size();
        if (m > n) return res;

        int cntP[26] = {0};
        int cntS[26] = {0};
        // 
        for (int i = 0; i < m; i++) {
            cntP[p[i]-'a']++;
            cntS[s[i]-'a']++;
        }
        // 
        bool ok = true;
        for (int i = 0; i < 26; i++) {
            if (cntP[i] != cntS[i]) {
                ok = false;
                break;
            }
        }
        if (ok) res.push_back(0);
        // 
        for (int l = 1; l <= n - m; l++) {
            // 
            cntS[s[l-1]-'a']--;
            // 
            cntS[s[l+m-1]-'a']++;

            // 
            ok = true;
            for (int i = 0; i <26; i++) {
                if (cntP[i] != cntS[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) res.push_back(l);
        }
        return res;
    }
};