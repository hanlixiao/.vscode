// 练习                                                     最大间距
//                                    给定一个无序的数组 nums，返回 数组在排序之后，相邻元素之间最大的差值 。如果数组元素个数小于 2，则返回 0 。
//                                    您必须编写一个在「线性时间」内运行并使用「线性额外空间」的算法。




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        if (minVal == maxVal) return 0;  // 全部字—样,间距0

        int bucketSize = (maxVal - minVal + n - 2) / (n - 1);  // 向上取整
        // 每个桶存：桶内最小值，桶内最大值；初始化
        vector<pair<int, int>> buckets(n - 1, {INT_MAX, INT_MIN});

        // 把元素放进对应桶
        for (int x : nums) {
            if (x == minVal || x == maxVal) continue;
            int idx = (x - minVal) / bucketSize;
            buckets[idx].first = min(buckets[idx].first, x);
            buckets[idx].second = max(buckets[idx].second, x);
        }

        int ans = 0;
        int prevMax = minVal;
        for (auto &b : buckets) {
            // 空桶跳过
            if (b.first > b.second) continue;
            ans = max(ans, b.first - prevMax);
            prevMax = b.second;
        }
        ans = max(ans, maxVal - prevMax);  // 处理最后，和maxVal的间距
        return ans;
    }
};