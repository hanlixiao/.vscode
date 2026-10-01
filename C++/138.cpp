// 练习                                            猜数字游戏
//                                写出一个秘密数字，并请朋友猜这个数字是多少。朋友每猜测一次，你就会给他一个包含下述信息的提示：
//                                猜测数字中有多少位属于数字和确切位置都猜对了（称为 "Bulls"，公牛），
//                                有多少位属于数字猜对了但是位置不对（称为 "Cows"，奶牛）。也就是说，这次猜测中有多少位非公牛数字可以通过重新排列转换成公牛数字。
//                                给你一个秘密数字 secret 和朋友猜测的数字 guess ，请你返回对朋友这次猜测的提示。
//                                提示的格式为 "xAyB" ，x 是公牛个数， y 是奶牛个数，A 表示公牛，B 表示奶牛。
//                                请注意秘密数字和朋友猜测的数字都可能含有重复数字。




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cntS[10] = {0}, cntG[10] = {0};
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                cntS[secret[i] - '0']++;
                cntG[guess[i] - '0']++;
            }
        }
        int cows = 0;
        for (int d = 0; d <= 9; d++) {
            cows += min(cntS[d], cntG[d]);
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};