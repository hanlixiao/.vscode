// 练习                                          被围绕的区域
//                              给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' 组成，捕获 所有 被围绕的区域：
//                              连接：一个单元格与水平或垂直方向上相邻的单元格连接。
//                              区域：连接所有 'O' 的单元格来形成一个区域。
//                              围绕：如果一个区域中的所有 'O' 单元格都不在棋盘的边缘，则该区域被包围。这样的区域 完全 被 'X' 单元格包围。
//                              通过 原地 将输入矩阵中的所有 'O' 替换为 'X' 来 捕获被围绕的区域。你不需要返回任何值。




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(vector<vector<char>>& board, int x, int y) {
        int m = board.size();
        int n = board[0].size();
        // 越界或者不是'0'直接返回
        if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'o') return;
        board[x][y] = '#';  // 标记边界连通的o
        // 遍历四个方向，递归扩散
        for (auto &d : dir) {
            int nx = x + d[0];
            int ny = y + d[1];
            dfs(board, nx, ny);
        }
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int m = board.size();
        int n = board[0].size();
        // 1.处理第一行、最后一行
        for (int j = 0; j < n; ++j) {
            dfs(board, 0, j);
            dfs(board, m - 1, j);
        }
        // 2.处理第一列、最后一列（排除已经处理过的四个角）
        for (int i = 1; i < m - 1; ++i) {
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }
        // 3.遍历矩阵，替换字符
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '0') board[i][j] = 'x';
                else if(board[i][j] == '#') board[i][j] = 'o';
            }
        }
    }
};