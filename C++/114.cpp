// 练习                                                课程表 II
//                                         现在你总共有 numCourses 门课需要选，记为 0 到 numCourses - 1。给你一个数组 prerequisites ，其中 prerequisites[i] = [ai, bi] ，表示在选修课程 ai 前 必须 先选修 bi 。
//                                         例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示：[0,1] 。
//                                         返回你为了学完所有课程所安排的学习顺序。可能会有多个正确的顺序，你只要返回 任意一种 就可以了。如果不可能完成所有课程，返回 一个空数组 。




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