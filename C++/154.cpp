#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // 返回pair：{选当前节点最大值，不选当前节点最大值}
    pair<int, int> dfs(TreeNode* node) {
        if (node == nullptr) {
            return {0, 0};
        }
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        // 选当前点，左右子都不能选
        int select = node->val + left.second + right.second;
        // 不选当前点，左右各自可以选或不选，取最大
        int notSelect = max(left.first, left.second) + max(right.first, right.second);
        return {select, notSelect};
    }

    int rob(TreeNode* root) {
        auto res = dfs(root);
        return max(res.first, res.second);
    }
};