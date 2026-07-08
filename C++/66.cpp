// 练习                                                       二叉树的锯齿形层序遍历
//                                           给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。




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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        bool reverse_flag = false;  // 第二层及以后反转
        while (!q.empty()) {
            int layerSize = q.size();
            vector<int> layer;
            for (int i = 0; i < layerSize; ++i) {
                TreeNode* cur = q.front();
                q.pop();
                layer.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            // 需要反转则倒置当前层
            if (reverse_flag) reverse(layer.begin(), layer.end());
            res.push_back(layer);
            reverse_flag = !reverse_flag;  // 需要反转则倒置当前层
        }
        return res;
    }  
};