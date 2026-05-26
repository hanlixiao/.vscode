// 练习                            螺旋矩阵
//                            给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        // 定义四个边界
        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;

        while (top <= bottom && left <= right) {
            // 1。从左到右遍历上边界
            for (int i = left; i <= right; ++i) {
                res.push_back(matrix[top][i]);
            }
            // 上边界收缩
            top++;

            // 2。从上到下遍历右边界
            for (int i = top; i <= bottom; ++i) {
                res.push_back(matrix[i][right]);
            }
            // 边界收缩
            right--;

            // 3。从右到左遍历下边界（需判断是否还有行）
            if (top <= bottom) {
                for (int i = right; i >= left; --i) {
                    res.push_back(matrix[bottom][i]);
                }
                // 下边界收缩
                bottom--;
            }

            // 4。从下到上遍历左边界（需判断是否还有列）
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    res.push_back(matrix[i][left]);
                }
                // 左边界收缩
                left++;
            }
        }

        return res;
    }
};