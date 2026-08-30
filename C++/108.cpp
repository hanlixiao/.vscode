// 练习                                          岛屿数量
//                                      给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
//                                      岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
//                                      此外，你可以假设该网格的四条边均被水包围。




#include <bits/stdc++.h>
using namespace std;

class Soluiton {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        // 越界或者当前不是陆地，直接返回
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||  grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';  // 标记已经访问过
        // 向上下左右四个方向扩散
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};