#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node*, Node*> mp;
        Node* cur = head;
        // 1. 创建所有副本节点，建立映射
        while (cur) {
            mp[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        // 2. 赋值next、random指针
        while (cur) {
            mp[cur]->next = mp[cur->next];
            mp[cur]->random = mp[cur->random];
            cur = cur->next;
        }
        return mp[head];
    }
};