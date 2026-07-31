// 练习                                           克隆图
//                                  给你无向 连通 图中一个节点的引用，请你返回该图的 深拷贝（克隆）。
//                                  图中的每个节点都包含它的值 val（int） 和其邻居的列表（list[Node]）。
//                                  class Node {
//                                      public int val;
//                                      public List<Node> neighbors;
//                                  }




#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neightbors;
    Node() {
        val = 0;
        neightbors = vector<Node*> ();
    }
    Node(int _val) {
        val = _val;
        neightbors = vector<Node*> ();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neightbors = _neighbors;
    }
};

class Solution {
public:
    // key:原图节点，value:克隆出来的新节点
    unordered_map<Node*, Node*> visited;

    Node* cloneGraph(Node* node) {
        // 边界：空节点
        if (node == nullptr) return nullptr;
        
        // 如果该节点已经克隆完成，直接返回克隆节点
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }

        // 1. 创建当前节点的克隆
        Node* cloneNode = new Node(node->val);
        visited[node] = cloneNode;

        // 2. 遍历原节点所有邻居，递归克隆邻居并加入克隆节点邻接表
        for (Node* neighbor : node->neightbors) {
            cloneNode->neightbors.push_back(cloneGraph(neighbor));
        }
        return cloneNode;
    }
};