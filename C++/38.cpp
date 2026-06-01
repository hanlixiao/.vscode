#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        // 要填入的数字，从1开始
        int num = 1;

        while (top <= bottom && left <= right) {
            // 1.从左到右填充上边界
            for (int i = left; i <= right; ++i) {
                matrix[top][i] = num++;
            }
            top++;

            // 2.从上到下填充右边界
            for (int i = top; i <= bottom; ++i) {
                matrix[i][right] = num++;
            }
            right--;

            // 3。从右到左填充下边界（需判断是否还有行）
            if (top <= bottom) {
                for (int i = right; i >= left; --i) {
                    matrix[bottom][i] = num++;
                }
                bottom--;
            }

            //4。从下到上填充左边界（需判断是否还有列）
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    matrix[i][left] = num++;
                }
                left++;
            }
        }
        return matrix;
    } 
};