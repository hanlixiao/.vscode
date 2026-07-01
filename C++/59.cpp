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