// 练习                                                         从前序与中序遍历序列构造二叉树
//                                               给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。




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
    vector<int> pre;
    TreeNode* build(int preL, int preR, int inL, int inR) {
        if (preL > preR) return nullptr;
        // 前序第一个为根
        int rootVal = pre[preL];
        TreeNode* root = new TreeNode(rootVal);
        // 根在中序的下标
        int mid = val2idx[rootVal];
        // 左子树节点总数
        int leftSize = mid - inL;
        // 左子树：前序[preL+1，preL+leftsize]，中序[inL，mid-1
        root->left = build(preL + 1, preL + leftSize, inL, mid - 1);
        // 右子树：前序[preL+leftSize+1，preR]，中序[mid+1，inR
        root->right = build(preL + leftSize + 1, preR, mid + 1, inR);
        return root;
    }

public:
    TreeNode* buiTree(vector<int>& preorder, vector<int>& inorder) {
        pre = preorder;
        // 建立值到中序下标的映射
        for (int i = 0; i < inorder.size(); ++i) {
            val2idx[inorder[i]] = i;
        }
        return build(0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};