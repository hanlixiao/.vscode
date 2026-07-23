// 练习                           旋转图像 
//                            给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
//                            你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。

 



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // 1．上下翻转 (相当于把图像垂直镜像。)
        // 只需要遍历一半的行数
        for (int i = 0; i < n / 2; ++i) {
            swap(matrix[i], matrix[n - 1 - i]);
        }

        // 2.沿主对角线翻转 (相当于把图像沿 y=x 轴镜像。)
        // 只需要遍历对角线右上方的元素
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};