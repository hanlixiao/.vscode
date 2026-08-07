#include <bits/stdc++.h>
using namespace std;

//双向链表节点
struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _val): key(_key), value(_val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;

    // 将节点移动到头部（标记为最近使用）
    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    // 删除某一个节点
    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // 在头结点之后插入新节点
    void addToHead(DLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    // 删除尾节点，返回被删掉的节点
    DLinkedNode* removeTail() {
        DLinkedNode* del = tail->prev;
        removeNode(del);
        return del;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        // 虚拟头、虚拟尾，简化边界判断，不用处理空链表
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        DLinkedNode* node = cache[key];
        moveToHead(node);  // 访问过后，更新为最近使用
        return node->value;
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            // key已存在：更新value，移到头部
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            // key不存在，新建节点
            DLinkedNode* newNode = new DLinkedNode(key, value);
            cache[key] = newNode;
            addToHead(newNode);
            size++;
            // 超过容量，淘汰最久未使用（尾部节点）
            if (size > capacity) {
                DLinkedNode* delNode = removeTail();
                cache.erase(delNode->key);  // 哈希表也要删掉
                delete delNode;
                size--;
            }
        }
    }
};