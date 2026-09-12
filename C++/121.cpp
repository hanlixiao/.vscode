// 练习                                             矩形面积
//                                      给你 二维 平面上两个 由直线构成且边与坐标轴平行/垂直 的矩形，请你计算并返回两个矩形覆盖的总面积。
//                                      每个矩形由其 左下 顶点和 右上 顶点坐标表示：
//                                      第一个矩形由其左下顶点 (ax1, ay1) 和右上顶点 (ax2, ay2) 定义。
//                                      第二个矩形由其左下顶点 (bx1, by1) 和右上顶点 (bx2, by2) 定义。




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