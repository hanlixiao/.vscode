#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string prev = "1";
        for (int i = 2; i <= n; ++i) {
            string curr = "";
            int count = 1;
            char say = prev[0];

            // 遍历上一项，生成当前项
            for (int j = 1; j < prev.size(); ++j) {
                if (prev[j] == say) {
                    count ++;
                } else {
                    curr += to_string(count) + say;
                    say = prev[j];
                    count = 1;
                }
            }

            curr += to_string(count) + say;
            prev = curr;
        }
        return prev;
    }  
};