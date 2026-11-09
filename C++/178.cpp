#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arr;
    Solution(vector<int>& nums) {
        arr = nums;
    }

    int pick(int target) {
        int res = -1;
        int cnt = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == target) {
                cnt++;
                // rand() % cnt == 0 ，概率 1/cnt 选中当前i
                if (rand() % cnt == 0) {
                    res = i;
                }
            }
        }
        return res;
    }
};