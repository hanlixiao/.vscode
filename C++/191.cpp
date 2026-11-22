// 练习                                                     扁平化多级双向链表
//                                               你会得到一个双链表，其中包含的节点有一个下一个指针、一个前一个指针和一个额外的 子指针 。这个子指针可能指向一个单独的双向链表，也包含这些特殊的节点。这些子列表可以有一个或多个自己的子列表，以此类推，以生成如下面的示例所示的 多层数据结构 。
//                                               给定链表的头节点 head ，将链表 扁平化 ，以便所有节点都出现在单层双链表中。让 curr 是一个带有子列表的节点。子列表中的节点应该出现在扁平化列表中的 curr 之后 和 curr.next 之前 。
//                                               返回 扁平列表的 head 。列表中的节点必须将其 所有 子指针设置为 null 。




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