// 练习                                                  添加与搜索单词 - 数据结构设计
//                                  请你设计一个数据结构，支持 添加新单词 和 查找字符串是否与任何先前添加的字符串匹配 。
//                                  实现词典类 WordDictionary ：
//                                  WordDictionary() 初始化词典对象
//                                  void addWord(word) 将 word 添加到数据结构中，之后可以对它进行匹配
//                                  bool search(word) 如果数据结构中存在字符串与 word 匹配，则返回 true ；否则，返回  false 。word 中可能包含一些 '.' ，每个 . 都可以表示任何一个字母。




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