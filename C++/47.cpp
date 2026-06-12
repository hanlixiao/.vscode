#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0, p2 = n - 1;
        int curr = 0;

        while (curr <= p2) {
            if (nums[curr] == 0) {
                swap(nums[curr], nums[p0]);
                p0++;
                curr++;
                } else if (nums[curr] == 2) {
                    swap(nums[curr], nums[p2]);
                    p2--;
                } else {
                    // nums[curr]== 1
                    curr++;
                }
            }
        }
    }
};