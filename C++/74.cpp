// 练习                                               填充每个节点的下一个右侧节点指针 II
//                              给定一个二叉树：
//                              struct Node {
//                                int val;
//                                Node *left;
//                                Node *right;
//                                Node *next;
//                              }
//                              填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL 。
//                              初始状态下，所有 next 指针都被设置为 NULL 。




#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int x, Node *left, Node *right, Node *next) : val(x), left(left), right(right), next(next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int layerSize = q.size();
            for (int i = 0; i < layerSize; ++i) {
                Node* cur = q.front();
                q.pop();
                // 不是当前层最后一个，指向下一个节点
                if (i < layerSize - 1) cur->next = q.front();
                else cur->next = nullptr;
                // 左右孩子入队，空节点不入队
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        return  root;
    }
};