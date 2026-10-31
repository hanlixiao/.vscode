#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> origin;
    vector<int> arr;

public:
    Solution(vector<int>& nums) {
        origin = nums;
        arr = nums;
    }

    vector<int> reset() {
        arr = origin;
        return arr;
    }

    vector<int> shuffle() {
        int n = arr.size();
        for (int i = n - 1; i > 0; --i) {
            // 在[0,i]随机选一个下标
            int j = rand() % (i + 1);
            swap(arr[i], arr[j]);
        }
        return arr;
    }
};