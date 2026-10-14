#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> tokens;
        // 
        int n = preorder.size();
        string tmp;
        for (int i = 0; i < n; i++) {
            if (preorder[i] == ',') {
                tokens.push_back(tmp);
                tmp.clear();
            } else {
                tmp += preorder[i];
            }
        }
        tokens.push_back(tmp);  // 

        int slots = 1;
        for (auto &s : tokens) {
            slots--;
            if (slots < 0) return false;
            if (s != "#") {
                slots += 2;
            }
        }
        return slots == 0;
    }
};