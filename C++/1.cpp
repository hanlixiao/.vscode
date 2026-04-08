#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if(numRows == 1) return s;

        vector<string> rows(numRows);
        int currentRow = 0;
        int step = 1;

        for(char c : s)
        {
            rows[currentRow] += c;
            if(currentRow == numRows - 1) step = -1;
            else if(currentRow == 0) step = 1;

            currentRow += step;
        }

        string res;
        for(string& row : rows)
        {
            res += row;
        }

        return res;
    }

    
}