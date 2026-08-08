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
    ListNode* insertionSortList(ListNode* head) {
        // 虚拟头结点，方便在链表头部插入节点
        ListNode* dummy = new ListNode(0);
        ListNode* cur = head;
        
        while(cur != nullptr) {
            // 保存下一个待处理节点
            ListNode* nextNode = cur->next;

            // pre用来遍历有序链表，找插入位置
            ListNode* pre = dummy;
            // 找到第一个比cur值大的节点的前一个位置
            while(pre->next != nullptr && pre->next->val < cur->val) {
                pre = pre->next;
            }

            // 把cur插入 pre 和pre->next之间
            cur->next = pre->next;
            pre->next = cur;
            
            // 处理原链表下一个节点
            cur = nextNode;
        }
        return dummy->next;
    }
};