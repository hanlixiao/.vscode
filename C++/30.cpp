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