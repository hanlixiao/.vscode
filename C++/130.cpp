#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> diffWayToCompute(string expression) {
        vector<int> res;
        bool hasOp = false;
        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];
            if (c == '+' || c == '-' || c== '*') {
                hasOp = true;
                auto left = diffWayToCompute(expression.substr(0, i));
                auto right = diffWayToCompute(expression.substr(i + 1));
                // 组合左右两边所有结果
                for (int l : left) {
                    for (int r : right) {
                        if (c == '+') res.push_back(l + r);
                        else if (c == '-') res.push_back(l - r);
                        else if (c == '*') res.push_back(l * r);
                    }
                }
            }
        }
        // 没有运算符，就是数字
        if (!hasOp) {
            res.push_back(stoi(expression));
        }
        return res;
    }
};