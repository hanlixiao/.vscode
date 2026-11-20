#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    Node() {
        val = false;
        isLeaf = false;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    vector<vector<int>> g;
    Node* construct(vector<vector<int>>& grid) {
        g = grid;
        return dfs(0, 0, grid.size());
    }

    // x,y:左上角，len:边长
    Node* dfs(int x, int y, int len) {
        // 检查当前区域是否全部相同
        if (check(x, y, len)) {
            return new Node(g[x][y] == 1, true);
        }
        int mid = len / 2;
        Node* tl = dfs(x, y, mid);
        Node* tr = dfs(x, y + mid, mid);
        Node* bl = dfs(x + mid, y, mid);
        Node* br = dfs(x + mid, y + mid, mid);
        // isLeaf=false，val随便填，这里填true
        return new Node(true, false, tl, tr, bl, br);
    }

    bool check(int x, int y, int len) {
        int val = g[x][y];
        for (int i = x; i < x + len; i++) {
            for (int j = y; j < y + len; j++) {
                if (g[i][j] != val) {
                    return false;
                }
            }
        }
        return true;
    }
};