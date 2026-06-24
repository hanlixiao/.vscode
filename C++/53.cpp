// 练习                                         删除排序链表中的重复元素 II
//                                      给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。



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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-101, head);
        ListNode* pre = dummy;
        ListNode* cur = head;
        while (cur != nullptr) {
            bool hasDup = false;
            //跳过所有相同值节点
            while (cur->next != nullptr && cur->val == cur->next->val) {
                hasDup = true;
                cur = cur->next;
            }
            if (hasDup) {
                // 截断全部重复段
                pre->next = cur->next;
            } else {
                // 当前值无重复，pre后移
                pre = pre->next;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};