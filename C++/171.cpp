// 练习                                                      文件的最长绝对路径
//                                                假设有一个同时存储文件和目录的文件系统。
//                                                在文本格式中，如下所示(⟶表示制表符)：
//                                                dir
//                                                ⟶ subdir1
//                                                ⟶ ⟶ file1.ext
//                                                ⟶ ⟶ subsubdir1
//                                                ⟶ subdir2
//                                                ⟶ ⟶ subsubdir2
//                                                ⟶ ⟶ ⟶ file2.ext
//                                                如果是代码表示，上面的文件系统可以写为 "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" 。'\n' 和 '\t' 分别是换行符和制表符。
//                                                文件系统中的每个文件和文件夹都有一个唯一的 绝对路径 ，即必须打开才能到达文件/目录所在位置的目录顺序，所有路径用 '/' 连接。上面例子中，指向 file2.ext 的 绝对路径 是 "dir/subdir2/subsubdir2/file2.ext" 。每个目录名由字母、数字和/或空格组成，每个文件名遵循 name.extension 的格式，其中 name 和 extension由字母、数字和/或空格组成。
//                                                给定一个以上述格式表示文件系统的字符串 input ，返回文件系统中 指向 文件 的 最长绝对路径 的长度 。 如果系统中没有文件，返回 0。




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