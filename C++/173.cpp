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