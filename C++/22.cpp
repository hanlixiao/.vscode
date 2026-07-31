// 练习                      有效的数独 
//                      请你判断一个 9 x 9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。
//                      数字 1-9 在每一行只能出现一次。
//                      数字 1-9 在每一列只能出现一次。
//                      数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。



#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 初始化三个数组，分别记录行、列、宫格中数字出现的次数
        // rows[i][num表示第i 行数字 num+1 出现的次数
        // cols[j][num表示第j列数字num+1出现的次数
        // boxes[k][num表示第k个宫格数字 num+1出现的次数
        int rows[9][9] = {0};
        int cols[9][9] = {0};
        int boxes[9][9] = {0};

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c != '.') {
                    // 将字符转换为 0-8 的索引
                    int num = c - '1';

                    // 计算当前格子所属的 3x3 宫格索引
                    int boxIndex = (i / 3) * 3 + (j / 3);

                    // 检查是否重复
                    if (rows[i][num] > 0 || cols[j][num] > 0 || boxes[boxIndex][num] > 0) {
                        // 发现重复，数独无效
                        return false;
                    }

                    // 标记该数字已出现
                    rows[i][num]++;
                    cols[j][num]++;
                    boxes[boxIndex][num]++;
                }
            }
        }
        // 遍历完成，无重复，数独有效
        return true;
    }
};