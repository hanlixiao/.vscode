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
    vector<int> res;
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);  // 左
        res.push_back(root->val);  // 根
        inorder(root->right);  // 右
    }

    int kthSamllest(TreeNode* root, int k) {
        inorder(root);
        return res[k - 1];
    }
};