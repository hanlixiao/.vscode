// 练习                      合并两个有序链表



#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 虚拟头结点
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        
        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val < p2->val) {
                cur->next = p1;
                p1 = p1->next;
            } else {
                cur->next = p2;
                p2 = p2->next;
            }
            cur = cur->next;
        }
        
        // 拼接剩余结点
        cur->next = (p1 != nullptr) ? p1 : p2;
        
        return dummy->next;
    }
};