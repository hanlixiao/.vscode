// 练习                                           为运算表达式设计优先级
//                                    给你一个由数字和运算符组成的字符串 expression ，按不同优先级组合数字和运算符，计算并返回所有可能组合的结果。你可以 按任意顺序 返回答案。
//                                    生成的测试用例满足其对应输出值符合 32 位整数范围，不同结果的数量不超过 104 。




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