// 练习                                                       打家劫舍 III
//                                        小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。
//                                        除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。
//                                        给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。




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