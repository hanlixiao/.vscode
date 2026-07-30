// 练习                    外观数列 
//                     外观数列」是一个数位字符串序列，由递归公式定义：
//                     countAndSay(1) = "1"
//                     countAndSay(n) 是 countAndSay(n-1) 的行程长度编码。
//                     行程长度编码（RLE）是一种字符串压缩方法，其工作原理是通过将连续相同字符（重复两次或更多次）替换为字符重复次数（运行长度）和字符的串联。例如，要压缩字符串 "3322251" ，我们将 "33" 用 "23" 替换，将 "222" 用 "32" 替换，将 "5" 用 "15" 替换并将 "1" 用 "11" 替换。因此压缩后字符串变为 "23321511"。
//                     给定一个整数 n ，返回 外观数列 的第 n 个元素。



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string prev = "1";
        for (int i = 2; i <= n; ++i) {
            string curr = "";
            int count = 1;
            char say = prev[0];

            // 遍历上一项，生成当前项
            for (int j = 1; j < prev.size(); ++j) {
                if (prev[j] == say) {
                    count ++;
                } else {
                    curr += to_string(count) + say;
                    say = prev[j];
                    count = 1;
                }
            }
            // 处理最后一段
            curr += to_string(count) + say;
            prev = curr;
        }
        return prev;
    }  
};