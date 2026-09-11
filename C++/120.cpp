// 练习                                          完全二叉树的节点个数
//                               给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。




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

class Soluion {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        int leftDep = 0, rightDep = 0;

        // 向左一直走，求左深度
        while (l != nullptr) {
            rightDep++;
            l = l->left;
        }
        // 向右一直走，求右深度
        while (r != nullptr) {
            rightDep++;
            r = r->right;
        }

        if (leftDep == rightDep) {
            // 满二叉树:2^(leftDep+1) - 1
            return (1 << (leftDep + 1)) - 1;
        } else {
            // 不是满二叉树，分开递归
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
    }
};