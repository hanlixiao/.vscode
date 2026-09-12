#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int computerArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        // 两个矩形各自面积
        int areaA = (ax2 - ax1) * (ay2 - ay1);
        int areaB = (bx2 - bx1) * (by2 - by1);

        // 重叠区域四个边
        int ox1 = max(ax1, bx1);
        int oy1 = max(ay1, by1);
        int ox2 = min(ax2, bx2);
        int oy2 = min(ay2, by2);

        int overlapW = ox2 - ox1;
        int overlapH = oy2 - oy1;
        int overlapArea = 0;
        if (overlapW > 0 && overlapH > 0) {
            overlapArea = overlapW * overlapH;
        }

        return areaA + areaB - overlapArea;
    }
};