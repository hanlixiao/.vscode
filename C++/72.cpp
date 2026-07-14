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
    vector<TreeNode*> nodes;
    void flatten(TreeNode* root) {
        dfs(root);
        for (int i = 0; i < nodes.size() - 1; ++i) {
            nodes[i]->left = nullptr;
            nodes[i]->right = nodes[i + 1];
        }
    }
    void dfs(TreeNode* cur) {
        if (!cur) return;
        nodes.push_back(cur);
        dfs(cur->left);
        dfs(cur->right);
    }
};