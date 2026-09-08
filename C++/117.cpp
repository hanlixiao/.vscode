// 练习                                                 数组中的第K个最大元素
//                                   给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
//                                   请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
//                                   你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。




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