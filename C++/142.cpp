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