#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        // 矩阵的层数
        int layers = min(m, n) / 2; 
        
        // 遍历每一层
        for (int l = 0; l < layers; ++l) {
            // 1. 提取当前层的所有元素
            vector<int> layer;
            // 上边界（从左到右）
            for (int c = l; c < n - l; ++c) layer.push_back(grid[l][c]);
            // 右边界（从上到下，排除首尾）
            for (int r = l + 1; r < m - l - 1; ++r) layer.push_back(grid[r][n - l - 1]);
            // 下边界（从右到左）
            for (int c = n - l - 1; c >= l; --c) layer.push_back(grid[m - l - 1][c]);
            // 左边界（从下到上，排除首尾）
            for (int r = m - l - 2; r > l; --r) layer.push_back(grid[r][l]);
            
            int len = layer.size();
            if (len == 0) continue;
            // 有效轮转次数
            int shift = k % len; 
            
            // 2. 轮转：将数组左移 shift 位
            vector<int> rotated(len);
            for (int i = 0; i < len; ++i) {
                rotated[i] = layer[(i + shift) % len];
            }
            
            // 3. 将轮转后的元素写回原层
            int idx = 0;
            // 上边界
            for (int c = l; c < n - l; ++c) grid[l][c] = rotated[idx++];
            // 右边界
            for (int r = l + 1; r < m - l - 1; ++r) grid[r][n - l - 1] = rotated[idx++];
            // 下边界
            for (int c = n - l - 1; c >= l; --c) grid[m - l - 1][c] = rotated[idx++];
            // 左边界
            for (int r = m - l - 2; r > l; --r) grid[r][l] = rotated[idx++];
        }
        return grid;
    }
};
