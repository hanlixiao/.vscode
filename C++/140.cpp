// 练习                                              二维区域和检索 - 矩阵不可变
//                                 给定一个二维矩阵 matrix，以下类型的多个请求：
//                                 计算其子矩形范围内元素的总和，该子矩阵的 左上角 为 (row1, col1) ，右下角 为 (row2, col2) 。
//                                 实现 NumMatrix 类：
//                                 NumMatrix(int[][] matrix) 给定整数矩阵 matrix 进行初始化
//                                 int sumRegion(int row1, int col1, int row2, int col2) 返回 左上角 (row1, col1) 、右下角 (row2, col2) 所描述的子矩阵的元素 总和 。




#include <bits/stdc++.h>
using namespace std;

class NumMatrix {
public:
    vector<vector<int>> pre;
    NumMatrix (vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return;
        int n = matrix[0].size();
        pre.assign(m + 1, vector<int> (n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                pre[i][j] = matrix[i - 1][j - 1] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return pre[row2+1][col2+1] - pre[row1][col2+1] - pre[row2+1][col1] + pre[row1][col1];
    }
};