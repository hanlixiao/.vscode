#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        // 四个方向：上、下、左、右
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // 遍历每一个起点
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0, dirs)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    // idx：当前匹配到word第几个字符
    bool dfs(vector<vector<char>>& board, string& word, int x, int y, int idx, int dirs[4][2]) {
        int m = board.size();
        int n = board[0].size();
        // 全部匹配完成
        if (idx == word.size()) return true;
        // 越界/字符不匹配
        if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != word[idx]) return false;

        // 原地标记已访问
        char temp = board[x][y];
        board[x][y] = '#';

        // 四个方向递归
        for (int d = 0; d < 4; ++d) {
            int nx = x + dirs[d][0];
            int ny = y + dirs[d][1];
            if (dfs(board, word, nx, ny, idx + 1, dirs)) return true;
        }

        // 回溯恢复字符
        board[x][y] = temp;
        return false;
    }
};