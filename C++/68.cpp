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
private:
    unordered_map<int, int> val2idx;
    vector<int> post;
    TreeNode* build(int postL, int postR, int inL, int inR) {
        if (postL > postR) return nullptr;
        // 后序最后一位是根
        int rootVal = post[postR];
        TreeNode* root = new TreeNode(rootVal);
        int mid = val2idx[rootVal];
        int leftSize = mid - inL;
        // 构造左子树
        root->left = build(postL, postL + leftSize - 1, inL, mid - 1);
        // 构造右子树
        root->right = build(postL + leftSize, postR - 1, mid + 1, inR);
        return root;
    }

public:
    TreeNode*buildTree(vector<int>& inorder, vector<int>& postorder) {
        post = postorder;
        // 建立中序值到下标的映射
        for (int i = 0; i < inorder.size(); ++i) {
            val2idx[inorder[i]]=i;
        }
        return build(0, postorder.size()-1, 0, inorder.size()-1);
    }
};