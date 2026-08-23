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

class BSTIterator {
private:
    vector<int> nums;
    int ptr;
    // 中序遍历，结果存入nums
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder (root->left);
        nums.push_back(root->val);
        inorder(root->right);
    }

public:
    BSTIterator(TreeNode* root) {
        inorder(root);
        ptr = 0;  // 指针初始在第一个元素前面
    }

    int next() {
        return nums[ptr++];
    }

    bool hasNext() {
        return ptr < nums.size();
    }
};