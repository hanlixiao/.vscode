#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        // 八个方向
        vector<pair<int, int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

        // 第一遍：打标记
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cnt = 0;
                for (auto &d : dirs) {
                    int nx = i + d.first;
                    int ny = j + d.second;
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                        // 原状态是活：1或者标记2（之前原始是活）
                        if (board[nx][ny] == 1 || board[nx][ny] == 2) {
                            cnt++;
                        }
                    }
                }
                // 当前本身是活细胞
                if (board[i][j] == 1) {
                    if (cnt < 2 || cnt > 3) {
                        board[i][j] = 2;  // 活→死，标记2
                    }
                    // cnt==2或3不变，依旧是1
                } else {
                    // 原来是死
                    if (cnt == 3) {
                        board[i][j] = 3;  //死→活，标记3
                    }
                }
            }
        }
        // 第二遍，把标记翻译成最终0/1
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 2) board[i][j] = 0;
                else if (board[i][j] == 3) board[i][j] = 1;
            }
        }
    }
};