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
    vector<vector<int>> leveOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;  // 空树直接返回空
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int layerSize = q.size();  // 当前层节点数量
            vector<int> layer;
            for (int i = 0; i < layerSize; ++i) {
                TreeNode* cur = q.front();
                q.pop();
                layer.push_back(cur->val);
                // 左右子节点入队
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            res.push_back(layer);
        }
        return res;
    }
};