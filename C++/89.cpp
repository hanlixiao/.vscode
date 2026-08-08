// 练习                                              对链表进行插入排序
//                                  给定单个链表的头 head ，使用 插入排序 对链表进行排序，并返回 排序后链表的头 。
//                                  插入排序 算法的步骤:
//                                  插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
//                                  每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
//                                  重复直到所有输入数据插入完为止。




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