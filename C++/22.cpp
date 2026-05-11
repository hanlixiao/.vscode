#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    bool isValidSudoku(<vector<vector<char>>>& board) {
        int rows[9][9] = {0};
        int cols[9][9] = {0};
        int boxes[9][9] = {0};

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c != '.') {
                    
                    int num = c - '1';


                    int boxIndex = (i / 3) * 3 + (j / 3);


                    if (rows[i][num] > 0 || cols[j][num] > 0 || boxes[boxIndex][num] > 0) {
                        return false;
                    }


                    rows[i][num]++;
                    cols[j][num]++;
                    boxes[boxIndex][num]++;
                }
            }
        }
        return true;
    }
};