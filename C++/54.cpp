// 练习                                               分隔链表
//                                     给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
//                                     你应当 保留 两个分区中每个节点的初始相对位置。



#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    ListNode *next;
    int val;
    ListNode() :val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *noxt) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // 两条链的虚拟头
        ListNode smallDummy, largeDummy;
        ListNode *small = &smallDummy, *large = &largeDummy;
        ListNode *cur = head;

        while (cur != nullptr) {
            if (cur->val < x) {
                small->next = cur;
                small = small->next;
            } else {
                large->next = cur;
                large = large->next;
            }
            cur = cur->next;
        }
        // 关键：切断大链尾部，避免环
        large->next = nullptr;
        // 小链末尾接大链有效起点
        small->next = largeDummy.next;
        return smallDummy.next;
    }
};