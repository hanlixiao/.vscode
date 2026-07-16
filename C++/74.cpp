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