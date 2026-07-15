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
                int sz = q.size();
                for (int i = 0; i < sz; ++i) {
                    Node* cur = q.front();
                    q.pop();
                    // 不是层末尾，指向下一个队首
                    if (i < sz - 1) {
                        cur->next = q.front();
                    } else {
                        cur->next = nullptr;
                    }
                    if (cur->left) q.push(cur->left);
                    if (cur->right) q.push(cur->right);
                }
            }
            return root;
        }
};