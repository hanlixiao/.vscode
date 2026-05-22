//练习                                   字母异位词分组
//                                给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
//                                例：输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
//                                    输出: [["bat"],["nat","tan"],["ate","eat","tea"]]



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 定义哈希表：Key是排序后的字符串，Value是原始字符串的列表
        unordered_map<string, vector<string>> map;

        // 1．遍历输入的每一个字符串
        for (const string& str: strs) {
            // 2．生成Key：复制一份当前字符串并排序
            string key = str;
            sort(key.begin(), key.end());

            // 3.归类：将原始字符串放入对应Key的列表中
            // map[key会自动创建一个空的 vector<string>（如果key 不存在)
            map[key].push_back(str);
        }

        // 4.收集结果
        vector<vector<string>> result;
        for (const auto& pair : map) {
            result.push_back(pair.second);
        }


        return result;
    }
};