#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        // 定义所有可能的基础值和对应符号（必须按从大到小排序）
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string res;
        
        // 贪心遍历：从最大的值开始尝试
        for (int i = 0; i < values.size(); ++i) {
            // 只要当前数值足够，就一直拼对应符号
            while (num >= values[i]) {
                res += symbols[i];
                num -= values[i];
            }
            // 剪枝：如果num减完了，直接退出循环
            if (num == 0) break;
        }
        
        return res;
    }
};