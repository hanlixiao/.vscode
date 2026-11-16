#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X') {
                    // 上面不是x，左边不是x
                    bool up = (i == 0) || (board[i-1][j] == '.');
                    bool left = (j == 0) || (board[i][j-1] == '.');
                    if (up && left) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};