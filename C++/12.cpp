// 练习                          给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。



#include <bits/stdc++.h>
using namespace std;


struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        // 创建虚拟头结点，统一处理删除头结点的情况
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // fast 先走 n 步
        for (int i = 0; i < n; ++i)
        {
            fast = fast->next;
        }

        // fast 和 slow 同步前进，直到 fast 到达尾结点
        while (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        // slow 的下一个结点就是要删除的结点
        slow->next = slow->next->next;

        return dummy->next;
    }

};