// 练习                                   Pow(x, n) 
//                                 实现 pow(x, n) ，即计算 x 的整数 n 次幂函数（即，xn ）。



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        // 使用1ong long防止n=-2147483648 取反时溢出
        long long N = n;

        // 如果n 是负数，转换为求（1/x）的正数次幂
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, - N);
    }

private:
    double quickMul(double x, long long n) {
        double ans = 1.0;
        // 当前x的贡献值，初始为 x^1
        double current_product = x;

        while (n > 0) {
            // 如果n 的二进制当前位是1，则贡献到结果中
            if (n % 2 == 1) {
                ans *= current_product;
            }
            // x自身不断平方：x->x^2->x^4->x^8。.
            current_product *= current_product;
            // n 右移一位，处理下一位
            n /= 2;
        }
        return ans;
    }
};