// 练习                    两两交换链表中的节点 
//                  给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。



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
    ListNode* swapPairs(ListNode* head)
    {
        // 创建虚拟头结点
        ListNode* dummy = new ListNode(0, head);
        ListNode* pre = dummy;
        ListNode* cur = head;

        // 当还有两个节点可以交换时
        while (cur != nullptr && cur->next != nullptr)
        {
            // 保存下一对节点的起始位置
            ListNode* nextPair =  cur->next->next;

            // 步骤1：前驱节点指向新的第一个节点
            pre->next = cur->next;
            // 步骤2：新的第一个节点指向原来的第一个节点
            cur->next->next = cur;
            // 步骤3：原来的第一个节点指向下一对节点
            cur->next = nextPair;

            // 移动指针到下一对节点的前驱和第一个节点
            pre = cur;
            cur = nextPair;
        }
        return dummy->next;
    }
};