#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string>bankSet(bank.begin(), bank.end());
        // end不在基因库，直接不可能
        if (!bankSet.count(end)) return -1;

        // 四个可选碱基
        vector<char> chs = {'A', 'C', 'G', 'T'};
        queue<pair<string, int>> q;
        unordered_set<string> vis;

        q.push({start, 0});
        vis.insert(start);

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            string gene = cur.first;
            int step = cur.second;

            // 遍历8个位置
            for (int i = 0; i < 8; i++) {
                char old = gene[i];
                for (char c : chs) {
                    if (c == old) continue;  // 没变，跳过
                    gene[i] = c;
                    if (gene == end) {
                        return step + 1;
                    }
                    // 在库里面且没访问过
                    if (bankSet.count(gene) && !vis.count(gene)) {
                        vis.insert(gene);
                        q.push({gene, step + 1});
                    }
                }
                gene[i] = old;  //恢复原位!回溯
            }
        }
        return -1;
    }
};