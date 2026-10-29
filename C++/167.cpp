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