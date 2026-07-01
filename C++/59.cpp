// 练习                                                 复原 IP 地址
//                                         有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
//                                         例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
//                                         给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> path;
        backtrack(s, 0, path, res);
        return res;
    }

private:
    // tart：当前切割起始下标，path：已切好的分段
    void backtrack(string& s, int start, vector<string>& path, vector<string>& res) {
        // 终止：已经分出4段
        if (path.size() == 4) {
            // 必须用完所有字符才是合法IP
            if (start == s.size()) {
                string ip = path[0];
                for (int i = 1; i < 4; ++i) ip += "." + path[i];
                res.push_back(ip);
            }
            return;
        }
        // 最多截取3位，且不能超出字符串末尾
        for (int len = 1; len <= 3; len++) {
            int end = start + len;
            if (end > s.size()) break;
            string seg = s.substr(start, len);
            // 规则1：前导零，长度>1且首字符是0→非法
            if (seg.size() > 1 && seg[0] == '0') continue;
            // 规则2：数值超过255→非法
            int num = stoi(seg);
            if (num > 255) continue;
            // 选择当前分段，递归下一段
            path.push_back(seg);
            backtrack(s, end, path, res);
            path.pop_back();  // 回溯撤销
        }
    }
};