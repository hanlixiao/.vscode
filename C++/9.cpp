#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int res = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n; ++i)
        {

            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == target) return target;

                if (abs(sum - target) < abs(res - target))
                {
                    res = sum;
                }

                if (sum < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        return res;
        
    }

};