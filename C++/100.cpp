#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                return {left + 1, right + 1};  // 转成题目要求的1开始下标
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {};  // 题目保证一定有解，这里不会走到
    }
};