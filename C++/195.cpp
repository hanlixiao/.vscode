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
    // 以node为起点向下，统计符合条件路径数
    long long dfs(TreeNode* node, long curSum, long long target) {
        if (!node) return 0;
        curSum += node->val;
        long long cnt = 0;
        if (curSum == target) cnt = 1;
        cnt += dfs(node->left, curSum, target);
        cnt += dfs(node->right, curSum, target);
        return cnt;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        // 当前节点作为起点+左子树 +右子树
        return dfs(root, 0, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
};