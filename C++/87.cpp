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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // 1.快慢指针找中点
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow是前半段最后一个节点
        ListNode* second = slow->next;
        slow->next = nullptr;  // 切断前后两段

        // 2.反转后半段链表
        second = reverseList(second);

        // 3.交替合并两个链表
        ListNode* p1 = head;
        ListNode* p2 = second;
        while (p2) {
            ListNode* next1 = p1->next;
            ListNode* next2 = p2->next;
            p1->next = p2;
            p2->next = next1;
            p1 = next1;
            p2 = next2;
        }
    }

private:
    // 反转链表辅助函数
    ListNode* reverseList(ListNode* cur) {
        ListNode* pre = nullptr;
        while (cur) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};