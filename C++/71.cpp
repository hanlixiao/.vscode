// 练习                                                   路径总和 II
//                                  给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
//                                  叶子节点 是指没有子节点的节点。




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
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return res;
        dfs(root, targetSum);
        return res;
    }

private:
    void dfs(TreeNode* node, int remain) {
        // 当前节点加入路径，剩余目标减去当前值
        path.push_back(node->val);
        remain -= node->val;
        
        // 叶子节点，且剩余和为θ，找到合法路径
        if (!node->left && !node->right && remain == 0) {
            res.push_back(path);
        }

        // 左右递归
        if (node->left) dfs(node->left, remain);
        if (node->right) dfs(node->right, remain);

        // 回溯：撤销当前节点
        path.pop_back();
    }
};