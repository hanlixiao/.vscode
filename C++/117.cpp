#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 分区函数：从大到小划分，返回pivot最终下标
    int partition(vector<int>& nums, int l, int r) {
        int pivot = nums[l];
        int i = l, j = r;
        while (i < j) {
            // 右边找 >= pivot 的数
            while (i < j && nums[j] <= pivot) j--;
            nums[i] = nums[j];
            // 左边找 <= pivot 的数
            while (i < j && nums[i] >= pivot) i++;
            nums[j] = nums[i];
        }
        nums[i] = pivot;
        return i;
    }

    int quickSelect(vector<int>& nums, int l, int r, int k) {
        int pos = partition(nums, l, r);
        if (pos == k - 1) return nums[pos];
        else if (pos < k - 1) {
            // 目标在右边
            return quickSelect(nums, pos + 1, r, k);
        } else {
            // 目标在左边
            return quickSelect(nums, l, pos - 1, k);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, k);
    }
};