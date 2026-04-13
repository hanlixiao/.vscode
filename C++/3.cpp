#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int n = s.size();
        int i = 0;

        while (i < n && s[i] == ' ')
        {
            i++;
        }

        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-'))
        {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        int res = 0;
        const int INT_MAX_BOUND = INT_MAX / 10;
        while (i < n && isdigit(s[i]))
        {
            int digit = s[i] - '0';

            if (res > INT_MAX_BOUND || (res == INT_MAX_BOUND && digit > 7))
            {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            res = res * 10 + digit;
            i++;
        }
        return res * sign;
    }

};