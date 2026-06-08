// 练习                                         简化路径
//                                   给你一个字符串 path ，表示指向某一文件或目录的 Unix 风格 绝对路径 （以 '/' 开头），请你将其转化为 更加简洁的规范路径。
//                                   在 Unix 风格的文件系统中规则如下：
//                                   一个点 '.' 表示当前目录本身。
//                                   此外，两个点 '..' 表示将目录切换到上一级（指向父目录）。
//                                   任意多个连续的斜杠（即，'//' 或 '///'）都被视为单个斜杠 '/'。
//                                   任何其他格式的点（例如，'...' 或 '....'）均被视为有效的文件/目录名称。
//                                   返回的 简化路径 必须遵循下述格式：
//                                   始终以斜杠 '/' 开头。
//                                   两个目录名之间必须只有一个斜杠 '/' 。
//                                   最后一个目录名（如果存在）不能 以 '/' 结尾。
//                                   此外，路径仅包含从根目录到目标文件或目录的路径上的目录（即，不含 '.' 或 '..'）。
//                                   返回简化后得到的 规范路径 。



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