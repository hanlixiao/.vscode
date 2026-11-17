#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* next[2];
    TrieNode() {
        next[0] = next[1] = nullptr;
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();
    // 插入数字到字典树，从高位30到0
    void insert(int x) {
        TrieNode* p = root;
        for (int i = 30; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (!p->next[bit]) {
                p->next[bit] = new TrieNode();
            }
            p = p->next[bit];
        }
    }
    // 查询x能和树里已有的数得到的最大异或
    int query(int x) {
        if (!root->next[0] && !root->next[1]) return 0;
        TrieNode* p = root;
        int res = 0;
        for (int i = 30; i > 0; i--) {
            int bit = ( x >> i) & 1;
            // 优先走相反的bit，异或得1
            int want = 1 - bit;
            if (p->next[want]) {
                res |= (1 << i);
                p = p->next[want];
            } else {
                // 相反不存在，只能走相同bit，异或为0
                p = p->next[bit];
            }
        }
        return res;
    }
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) {
            insert(x);
            ans = max(ans, query(x));
        }
        return ans;
    }
};