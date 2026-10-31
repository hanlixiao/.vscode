// 练习                                                    打乱数组
//                                            给你一个整数数组 nums ，设计算法来打乱一个没有重复元素的数组。打乱后，数组的所有排列应该是 等可能 的。
//                                            实现 Solution class:
//                                            Solution(int[] nums) 使用整数数组 nums 初始化对象
//                                            int[] reset() 重设数组到它的初始状态并返回
//                                            int[] shuffle() 返回数组随机打乱后的结果




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