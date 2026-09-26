#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n - 1;
        int ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            int h_candidate = n - mid;
            if (citations[mid] >= h_candidate) {
                ans = h_candidate;
                right = mid - 1;  // 往左，试图找更大h
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};