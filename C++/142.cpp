// 练习                                           区域和检索 - 数组可修改
//                                给你一个数组 nums ，请你完成两类查询。
//                                其中一类查询要求 更新 数组 nums 下标对应的值
//                                另一类查询要求返回数组 nums 中索引 left 和索引 right 之间（ 包含 ）的nums元素的 和 ，其中 left <= right
//                                实现 NumArray 类：
//                                NumArray(int[] nums) 用整数数组 nums 初始化对象
//                                void update(int index, int val) 将 nums[index] 的值 更新 为 val
//                                int sumRange(int left, int right) 返回数组 nums 中索引 left 和索引 right 之间（ 包含 ）的nums元素的 和 （即，nums[left] + nums[left + 1], ..., nums[right]）




#include <bits/stdc++.h>
using namespace std;

class NumArray {
private:
    vector<int> tree;
    vector<int> nums;
    int n;

    // lowbit
    int lowbit(int x) {
        return x & (-x);
    }
    // idx:树状数组下标(从1开始),delta增加的值
    void add(int idx, int delta) {
        while (idx <= n) {
            tree[idx] += delta;
            idx += lowbit(idx);
        }
    }
    // 查询[1..idx]前缀和
    int query(int idx) {
        int res = 0;
        while (idx > 0) {
            res += tree[idx];
            idx -= lowbit(idx);
        }
        return res;
    }

public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        tree.resize(n + 1, 0);
        // 初始化树状数组
        for (int i = 0; i < n; i++) {
            add(i + 1, nums[i]);
        }
    }

    void update(int index, int val) {
        int delta = val - nums[index];
        nums[index] = val;
        add(index + 1, delta);
    }

    int sumRange(int left, int right) {
        // 原数组left对应树状数组left+1;right→right+1
        return query(right + 1) - query(left);
    }
};