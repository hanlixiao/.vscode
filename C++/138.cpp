#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cntS[10] = {0}, cntG[10] = {0};
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                cntS[secret[i] - '0']++;
                cntG[guess[i] - '0']++;
            }
        }
        int cows = 0;
        for (int d = 0; d <= 9; d++) {
            cows += min(cntS[d], cntG[d]);
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};