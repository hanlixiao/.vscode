#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // 1.邻接表 + 入度数组
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);
        for (auto & edge : prerequisites) {
            int a = edge[0], b = edge[1];
            adj[b].push_back(a);  // 
            inDegree[a]++;
        }
        // 2.队列放入入度为0的点
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        vector<int> res;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            res.push_back(cur);
            // 遍历后继
            for (int next : adj[cur]) {
                inDegree[next]--;
                if (inDegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        // 判断是否存在环
        if (res.size() == numCourses) return res;
        else return {};
    }
};