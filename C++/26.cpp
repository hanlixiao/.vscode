// 练习                              字符串相乘 
//                            给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
//                            注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        // 特殊情况处理：如果任意一个数是“θ“，结果就是“θ"
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        int m = num1.size();
        int n = num2.size();


        // 结果最多有m + n 位
        vector<int> pos(m + n, 0);


        // 从右往左遍历num1
        for (int i = m - 1; i >= 0; i--) {
            // 从右往左遍历num2
            for (int j = n - 1; j >= 0; j--) {
                // 将字符转换为数字
                int digit1 = num1[i] - '0';
                int digit2 = num2[j] - '0';

                // 计算乘积
                int mul = digit1 * digit2;

                // 计算在 pos 数组中的位置
                // p1 是进位位置，p2 是当前位位置
                int p1 = i + j;
                int p2 = i + j + 1;
                

                // 加上之前的累加值（因为可能之前已经有数字落在 p2位置了）
                int sum = mul + pos[p2];

                // 更新 p2 位置的值（取个位)
                pos[p2] = sum % 10;

                // 更新 p1位置的值（进位累加）
                pos[p1] += sum / 10;
            }
        }

        // 将数组转换为字符串
        string result;
        for (int p : pos) {
            // 跳过前导零
            if (!(result.empty() && p == 0)) {
                result.push_back(p + '0');
            }
        }

        return result.empty() ? "0" : result;
    }
};