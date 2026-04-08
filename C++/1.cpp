// 练习            Z 字形变换
//                将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。



#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        // 边界情况行数为1时 直接返回原字符串
        if(numRows == 1) return s;

        // 初始化numRows个空字符串 对应每一行
        vector<string> rows(numRows);
        int currentRow = 0;
        // 1表示向下 -1表示向上
        int step = 1;

        for(char c : s)
        {
            // 将字符加入对应的行
            rows[currentRow] += c;

            // 到达最底部改为向上
            if(currentRow == numRows - 1) step = -1;
            // 到达对顶部改为向下
            else if(currentRow == 0) step = 1;

            // 更新当前行号
            currentRow += step;
        }

        // 按行拼接所有字符串
        string res;
        for(string& row : rows)
        {
            res += row;
        }

        return res;
    }

    
}