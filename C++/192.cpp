// 练习                                                           最小基因变化
//                                                       基因序列可以表示为一条由 8 个字符组成的字符串，其中每个字符都是 'A'、'C'、'G' 和 'T' 之一。
//                                                       假设我们需要调查从基因序列 start 变为 end 所发生的基因变化。一次基因变化就意味着这个基因序列中的一个字符发生了变化。
//                                                       例如，"AACCGGTT" --> "AACCGGTA" 就是一次基因变化。
//                                                       另有一个基因库 bank 记录了所有有效的基因变化，只有基因库中的基因才是有效的基因序列。（变化后的基因必须位于基因库 bank 中）
//                                                       给你两个基因序列 start 和 end ，以及一个基因库 bank ，请你找出并返回能够使 start 变化为 end 所需的最少变化次数。如果无法完成此基因变化，返回 -1 。
//                                                       注意：起始基因序列 start 默认是有效的，但是它并不一定会出现在基因库中。




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