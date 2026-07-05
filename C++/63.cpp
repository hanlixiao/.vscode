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
    long long pre = LLONG_MIN;  // 用1ong 1ong避免INT_MIN边界冲突
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        // 递归左子树
        if (!isValidBST(root->left)) return false;
        // 判断是否递增
        if (root->val <= pre) return false;
        pre = root->val;
        // 递归右子树
        return isValidBST(root->right);
    }
};