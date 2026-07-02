// 练习                                         不同的二叉搜索树 II
//                                  给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值从 1 到 n 互不相同的不同 二叉搜索树 。可以按 任意顺序 返回答案。




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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return build(1, n);
    }

private:
    // 
    vector<TreeNode*> build(int l, int r) {
        vector<TreeNode*> res;
        // 
        if (l > r) {
            res.push_back(nullptr);
            return res;
        }
        // 
        for (int i = 1; i <= r; ++i) {
            // 
            vector<TreeNode*> leftTrees = build(l, i - 1);
            // 
            vector<TreeNode*> rightTrees = build(i + 1, r);
            // 
            for (auto left : leftTrees) {
                for (auto right : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};