#include <bits/stdc++.h>
using namespace std;

// 定义链表节点结构
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // 1．边界情况处理
        if (!head || !head->next || k == 0) return head;

        // 2．计算链表长度，并找到尾节点
        int len = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }
        
        // 3.优化k值
        // 如果Κ 是长度的倍数，旋转后等于没动
        k = k % len;
        if (k == 0) return head;

        // 4.形成环
        tail->next = head;

        // 5．寻找新的尾部节点
        // 我们需要走len - k步到达新的尾部
        // 例如：长度5，右移2。新头是倒数第2个(索引3)，新尾是索引2。
        // 从头开始走5-2=3步，刚好停在索引2的位置。
        int stepsToNewTail = len - k;
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewTail; ++i) {
            newTail = newTail->next;
        }

        // 6．断开环，确立新头
        ListNode*newHead = newTail->next;
        newTail->next = nullptr;


        return newHead;
    }
};