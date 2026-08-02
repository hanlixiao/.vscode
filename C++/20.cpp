// 练习                       循环轮转矩阵 
//                    给你一个大小为 m x n 的整数矩阵 grid​​​ ，其中 m 和 n 都是 偶数 ；另给你一个整数 k 。
//                    矩阵的循环轮转是通过分别循环轮转矩阵中的每一层完成的。在对某一层进行一次循环旋转操作时，层中的每一个元素将会取代其 逆时针 方向的相邻元素。
//                    返回执行 k 次循环轮转操作后的矩阵。
//                    输入：grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2
//                    输出：[[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]




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
