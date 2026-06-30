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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0, head);
        ListNode* pre = &dummy;
        // 1.走到left-1位置，pre是反转区间前一个节点
        for (int i = 1; i < left; ++i) {
            pre = pre->next;
        }
        ListNode* subHead = pre->next;  // 区间第一个节点（反转后变尾）
        ListNode* cur = subHead;
        ListNode* prev = nullptr;
        // 2.反转right-left+1 个节点
        for (int i = 0; i <= right - left; ++i) {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        // 3.拼接：pre连反转后的头prev，原区间头subHead连后面的cur
        pre->next = prev;
        subHead->next = cur;
        return dummy.next;
    }
};