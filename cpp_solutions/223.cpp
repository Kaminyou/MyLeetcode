class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        // duplicate area
        int left = max(ax1, bx1);
        int right = min(ax2, bx2);
        int bottom = max(ay1, by1);
        int top = min(ay2, by2);
        
        int areaA = (ax2 - ax1) * (ay2 - ay1);
        int areaB = (bx2 - bx1) * (by2 - by1);
        
        int res = areaA + areaB;
        if (left < right && bottom < top) {
            int duplicate = (right - left) * (top - bottom);
            res -= duplicate;
        }
        return res;
    }
};