#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        const int INT_MAX_BOUND = INT_MAX / 10;
        const int INT_MIN_BOUND = INT_MIN / 10;

        int res = 0;
        while (x != 0)
        {
            int digit = x % 10;

            if (res > INT_MAX_BOUND || (res == INT_MAX_BOUND && digit > 7))
            {
                return 0;
            }
            if (res < INT_MIN_BOUND || (res == INT_MIN_BOUND && digit < -8))
            {
                return 0;
            }

            res = res * 10 + digit;
            x /= 10
        }
        return res;
    }

}