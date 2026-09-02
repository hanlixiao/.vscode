// 练习                                                   课程表
//                                         你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。
//                                         在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。
//                                         例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
//                                         请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。




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