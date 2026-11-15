// 练习                                                    太平洋大西洋水流问题
//                                           有一个 m × n 的矩形岛屿，与 太平洋 和 大西洋 相邻。 “太平洋” 处于大陆的左边界和上边界，而 “大西洋” 处于大陆的右边界和下边界。
//                                           这个岛被分割成一个由若干方形单元格组成的网格。给定一个 m x n 的整数矩阵 heights ， heights[r][c] 表示坐标 (r, c) 上单元格 高于海平面的高度 。
//                                           岛上雨水较多，如果相邻单元格的高度 小于或等于 当前单元格的高度，雨水可以直接向北、南、东、西流向相邻单元格。水可以从海洋附近的任何单元格流入海洋。
//                                           返回网格坐标 result 的 2D 列表 ，其中 result[i] = [ri, ci] 表示雨水从单元格 (ri, ci) 流动 既可流向太平洋也可流向大西洋 。




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 四个方向:上下左右
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, -1}};

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& vis, int r, int c) {
        vis[r][c] = true;
        int m = heights.size(), n = heights[0].size();
        for (auto &d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];
            // 边界合法、没访问过、高度>=当前（反向:往高处走)
            if (nr > 0 && nr < m && nc > 0 && nc < n && !vis[nr][nc] && heights[nr][nc] > heights[r][c]) {
                dfs(heights, vis, nr, nc);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        if (m == 0) return {};
        int n = heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n, false));  // 能流到太平洋
        vector<vector<bool>> atl(m, vector<bool>(n, false));  // 能流到大西洋

        //太平洋:第一行所有点
        for (int j = 0; j < n; j++) dfs(heights, pac, 0, j);
        // 太平洋:第一列所有点
        for (int i = 0; i < m; i++) dfs(heights, atl, i, 0);

        // 大西洋:最后一行所有点
        for (int j = 0; j < n; j++) dfs(heights, atl, m-1, j);
        // 大西洋:最后一列所有点
        for (int i = 0; i < m; i++) dfs(heights, atl, i, n-1);

        vector<vector<int>> res;
        // 找同时满足两个条件的坐标
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pac[i][j] && atl[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};