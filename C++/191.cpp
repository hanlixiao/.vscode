#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
        Node* cur = head;
        while (cur) {
            // 没有子节点，直接下一个
            if (!cur->child) {
                cur = cur->next;
                continue;
            }
            // 有子链表，开始拼接
            Node* nextNode = cur->next;
            Node* childHead = cur->child;
            Node* tail = childHead;
            // 找到子链表尾部
            while (tail->next) {
                tail = tail->next;
            }
            // cur 和 child 相连
            cur->next = childHead;
            childHead->prev = cur;
            // 子尾 和 原来后面节点相连
            tail->next = nextNode;
            if (nextNode) {
                nextNode->prev = tail;
            }
            // 移动到子链表第一个节点，继续往下扫（子链表里面还可能嵌套child）
            cur->child = nullptr;
            // 移动到子链表第一个节点，继续往下扫（子链表里面还可能嵌套child）
            cur = cur->next;
        }
        return head;
    }
};