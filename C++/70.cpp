// 练习                                               有序链表转换二叉搜索树
//                                   给定一个单链表的头节点  head ，其中的元素 按升序排序 ，将其转换为 平衡 二叉搜索树。




#include <bits/stdc++.h>
using namespace std;

// 链表节点定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 二叉树节点定义
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    TreeNode* build(ListNode* head, ListNode* tail) {
        if (head == tail) return nullptr;
        // 快慢指针找中点
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next;
        }
        // slow是区间中点
        TreeNode* root = new TreeNode(slow->val);
        root->left = build(head, slow);
        root->right = build(slow->next, tail);
        return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        return build(head, nullptr);
    }
};