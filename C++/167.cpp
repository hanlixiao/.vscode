// 练习                                                      有序矩阵中第 K 小的元素
//                                            给你一个 n x n 矩阵 matrix ，其中每行和每列元素均按升序排序，找到矩阵中第 k 小的元素。
//                                            请注意，它是 排序后 的第 k 小元素，而不是第 k 个 不同 的元素。
//                                            你必须找到一个内存复杂度优于 O(n2) 的解决方案。




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n-1][n-1];
        while (l < r) {
            int mid = l + (r - l) / 2;
            int cnt = 0;
            int i = n - 1, j = 0;
            while (i >= 0 && j < n) {
                if (matrix[i][j] <= mid) {
                    cnt += i + 1;
                    j++;
                } else {
                    i--;
                }
            }
            if (cnt < k) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};