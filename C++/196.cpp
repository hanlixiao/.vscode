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