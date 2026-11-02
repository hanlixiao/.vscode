#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int lengthLongestPath(string input) {
        stack<int> st;
        int maxLen = 0;
        int n = input.size();
        int i = 0;
        while (i < n) {
            // 统计\t的数量，得到depth
            int depth = 0;
            while (i < n && input[i] == '\t') {
                depth++;
                i++;
            }
            // 读取名字
            int nameLen = 0;
            bool isFile = false;
            while (i < n && input[i] != '\n') {
                if (input[i] == '.') isFile = true;
                nameLen++;
                i++;
            }
            i++;  // 跳过\n

            // 栈缩到depth层
            while (st.size() > depth) st.pop();

            int curTotal = 0;
            if (!st.empty()) curTotal = st.top() + 1;  // +1 是 '/'
            curTotal += nameLen;

            if (isFile) {
                maxLen = max(maxLen, curTotal);
            } else {
                st.push(curTotal);
            }
        }
        return maxLen;
    }
};