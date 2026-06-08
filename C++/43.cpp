#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        //使用vector模拟栈
        vector<string> stack;
        stringstream ss(path);
        string token;

        // 1．按/’分割字符串并处理每个部分
        while (getline(ss, token, '/')) {
            // 如果是空字符串（因为连续斜杠）或者“."，直接跳过
            if (token == "" || token == ".") {
                continue;
            }
            // 如果是“.."，表示返回上一级目录
            else if (token == "..") {
                if (!stack.empty()) {
                    stack.pop_back(); // 出栈
                }
            }
            // 香则是有效的目录名，入栈
            else {
                stack.push_back(token);
            }
        }
        
        // 2．如果栈为空，说明回到了根目录
        if (stack.empty()) {
            return "/";
        }

        // 3.拼接结果
        string result = "";
        for (const string& dir : stack) {
            result += "/" + dir;
        }

        return result;
    }
};