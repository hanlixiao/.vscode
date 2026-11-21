// 练习                                                              N 叉树的层序遍历
//                                                   定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。
//                                                   树的序列化输入是用层序遍历，每组子节点都由 null 值分隔。




#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();  // 当前层节点个数
            vector<int> layer;
            for (int i =0 ; i < sz; i++) {
                Node* cur = q.front();
                q.pop();
                layer.push_back(cur->val);
                // 把当前节点所有子节点入队
                for (Node* child : cur->children) {
                    q.push(child);
                }
            }
            res.push_back(layer);
        }
        return res;
    }
};