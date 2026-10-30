// 练习                                                     链表随机节点
//                                        给你一个单链表，随机选择链表的一个节点，并返回相应的节点值。每个节点 被选中的概率一样 。
//                                        实现 Solution 类：
//                                        Solution(ListNode head) 使用整数数组初始化对象。
//                                        int getRandom() 从链表中随机选择一个节点并返回该节点的值。链表中所有节点被选中的概率相等。




#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
private:
    ListNode* head;

public:
    Solution(ListNode*head) {
        this->head = head;
    }
    
    int getRandom() {
        int res = 0;
        int cnt = 0;
        ListNode* cur = head;
        while (cur != nullptr) {
            cnt++;
            // rand() % cnt == 0 概率是 1/cnt
            if (rand() % cnt == 0) {
                res = cur->val;
            }
            cur = cur->next;
        }
        return res;
    }
};