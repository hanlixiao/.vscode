// 练习                                       生命游戏
//                                    给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态： 1 即为 活细胞 （live），或 0 即为 死细胞 （dead）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：
//                                    如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
//                                    如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
//                                    如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
//                                    如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
//                                    下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是 同时 发生的。给你 m x n 网格面板 board 的当前状态，返回下一个状态。
//                                    给定当前 board 的状态，更新 board 到下一个状态。
//                                    注意 你不需要返回任何东西。




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