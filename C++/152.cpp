// 练习                                                         验证二叉树的前序序列化
//                                            序列化二叉树的一种方法是使用 前序遍历 。当我们遇到一个非空节点时，我们可以记录下这个节点的值。如果它是一个空节点，我们可以使用一个标记值记录，例如 #。




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> tokens;
        // 分割字符串，按逗号拆分
        int n = preorder.size();
        string tmp;
        for (int i = 0; i < n; i++) {
            if (preorder[i] == ',') {
                tokens.push_back(tmp);
                tmp.clear();
            } else {
                tmp += preorder[i];
            }
        }
        tokens.push_back(tmp);  // 最后一段

        int slots = 1;
        for (auto &s : tokens) {
            slots--;
            if (slots < 0) return false;
            if (s != "#") {
                slots += 2;
            }
        }
        return slots == 0;
    }
};