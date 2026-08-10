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
    ListNode* sortList(ListNode*head) {
        // 递归终止：空链表或单个节点天然有序
        if (!head || !head->next) return head;

        // 1. 快慢指针找中点
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 切断左右链表
        ListNode* mid = slow->next;
        slow->next = nullptr;

        // 2. 递归排序左右两部分
        ListNode* left = sortList(head);
        ListNode* right = sortList(head);

        // 3. 合并两个有序链表
        return merge(left, right);
    }

private:
    // 合并两个升序链表
    ListNode* merge(ListNode* l1, ListNode*l2) {
        ListNode dummy(0);
        ListNode* cur = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        // 拼接剩余部分
        cur->next = l1 ? l1 : l2;
        return dummy.next;
    }
};