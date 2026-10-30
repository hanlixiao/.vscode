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