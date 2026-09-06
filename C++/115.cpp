#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEnd;  // 
    TrieNode() {
        for (int i = 0; i < 26; ++i) children[i] = nullptr;
        isEnd = false;
    }
};

class WordDictionary {
private:
    TrieNode* root;

    // DFS递归搜索：pos当前匹配到第几个字符
    bool dfs(TrieNode* node, string & word, int pos) {
        if (pos == word.size()) {
            return node->isEnd;
        }
        char c = word[pos];
        if (c != '.') {
            // 普通字母，走唯一分支
            int idx = c - 'a';
            if (!node->children[idx]) return false;
            return dfs(node->children[idx], word, pos + 1);
        } else {
            // 是'."，遍历全部26个子节点尝试
            for (int i = 0; i < 26; i++) {
                if (node->children[i]) {
                    if (dfs(node->children[i], word, pos + 1)) {
                        return true;
                    }
                }
            }
            return false;
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            int  idx = c - 'a';
            if (!cur->children[idx]) {
                cur->children[idx] = new TrieNode();
            }
            cur = cur->children[idx];
        }
        cur->isEnd = true;
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }
};