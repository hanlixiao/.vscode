// 练习                                                                 恢复二叉搜索树
//                                             给你二叉搜索树的根节点 root ，该树中的 恰好 两个节点的值被错误地交换。请在不改变其结构的情况下，恢复这棵树 。




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
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* pre = nullptr;

    void inorder(TreeNode* cur) {
        if (!cur) return;
        inorder(cur->left);
        
        // 发现逆序对
        if (pre != nullptr && pre->val > cur->val) {
            if (first == nullptr) first = pre;  // 第一次逆序，标记第一个错误节点
            second = cur;  // 第二次逆序覆盖第二个错误节点
        }
        pre = cur;

        inorder(cur->right);
    }

public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        // 交换两个出错节点的值
        swap(first->val, second->val);
    }
};