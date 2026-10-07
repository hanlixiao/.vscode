// 练习                                           最小高度树
//                                  树是一个无向图，其中任何两个顶点只通过一条路径连接。 换句话说，任何一个没有简单环路的连通图都是一棵树。
//                                  给你一棵包含 n 个节点的树，标记为 0 到 n - 1 。给定数字 n 和一个有 n - 1 条无向边的 edges 列表（每一个边都是一对标签），其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间存在一条无向边。
//                                  可选择树中任何一个节点作为根。当选择节点 x 作为根节点时，设结果树的高度为 h 。在所有可能的树中，具有最小高度的树（即，min(h)）被称为 最小高度树 。
//                                  请你找到所有的 最小高度树 并按 任意顺序 返回它们的根节点标签列表。
//                                  树的 高度 是指根节点和叶子节点之间最长向下路径上边的数量。

//                                       一棵树的最小高度的根，等价于**树的中心（重心）**。
//                                       一棵树最多只能有 **1 个或者 2 个重心**！




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};  // 特殊边界只有一个点
        // 邻接表
        vector<vector<int>> adj(n);
        // 保存度数
        vector<int> degree(n, 0);
        // 构建无向图
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        queue<int> q;
        // 初始叶子（度数等于1）入队
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        // 剩余没有删除的节点数
        int remain = n;
        // 只要剩下多于2个点，继续剥叶子
        while (remain > 2) {
            // 当前这一层叶子数量
            int sz = q.size();
            // 删掉sz个叶子
            remain -= sz;
            for (int i = 0; i < sz; i++) {
                int cur = q.front(); 
                q.pop();
                // 遍历cur的所有邻居
                for(int neighbor : adj[cur]) {
                    degree[neighbor]--;
                    // 邻居度数变成1，说明它变成新叶子了，加入队列下一轮删除
                    if (degree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }
        // 队列剩下的就是重心，收集答案返回
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};