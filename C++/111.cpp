#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 1.构建邻接表
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (auto& edge : prerequisites) {
            int a = edge[0];
            int b = edge[1];
            adj[b].push_back(a);  // b -> a
            inDegree[a]++;
        }

        // 2.初始化队列，入度为θ的节点入队
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) q.push(i);
        }

        int count = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            count++;

            // 遍历后继节点
            for (int next : adj[cur]) {
                inDegree[next]--;
                if (inDegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        return count == numCourses;
    }
};