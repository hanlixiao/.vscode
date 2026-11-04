// 练习                                                 UTF-8 编码验证
//                                            给定一个表示数据的整数数组 data ，返回它是否为有效的 UTF-8 编码。
//                                            UTF-8 中的一个字符可能的长度为 1 到 4 字节，遵循以下的规则：
//                                            对于 1 字节 的字符，字节的第一位设为 0 ，后面 7 位为这个符号的 unicode 码。
//                                            对于 n 字节 的字符 (n > 1)，第一个字节的前 n 位都设为1，第 n+1 位设为 0 ，后面字节的前两位一律设为 10 。剩下的没有提及的二进制位，全部为这个符号的 unicode 码。
//                                            这是 UTF-8 编码的工作方式：
//                                                  Number of Bytes  |        UTF-8 octet sequence
//                                                                   |              (binary)
//                                               --------------------+---------------------------------------------
//                                                        1          | 0xxxxxxx
//                                                        2          | 110xxxxx 10xxxxxx
//                                                        3          | 1110xxxx 10xxxxxx 10xxxxxx
//                                                        4          | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
//                                            x 表示二进制形式的一位，可以是 0 或 1。
//                                            注意：输入是整数数组。只有每个整数的 最低 8 个有效位 用来存储数据。这意味着每个整数只表示 1 字节的数据。




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int cnt = 0;  // 需要等待的后续字节数量
        for (int num : data) {
            // 只保留低8位
            int b = num & 0xFF;
            if (cnt > 0) {
                // 必须是 10xxxxxx
                if ((b & 0xC0) != 0x80) return false;
                cnt--;
            } else  {
                if ((b & 0x80) == 0) {
                    // 0xxxxxxx 1字节，cnt不变
                    continue;
                } else if ((b & 0xE0) == 0xC0) {
                    // 110xxxxx 2字节，后续1个
                    cnt = 1;
                } else if ((b & 0xF0) == 0xE0) {
                    // 1110xxxx 3字节，后续2个
                    cnt = 2;
                } else if ((b & 0xF8) == 0xF0) {
                    // 11110xxx 4字节，后续3个
                    cnt = 3;
                } else {
                    // 10开头或者5个1，非法
                    return false;
                }
            }
        }
        return cnt == 0;
    }
};