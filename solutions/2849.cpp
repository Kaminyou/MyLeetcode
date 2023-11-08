class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int dx = abs(sx - fx);
        int dy = abs(sy - fy);
        int minT = min(dx, dy) + abs(dx - dy);
        if (minT == 0 && t == 1) return false;
        return t >= minT;
    }
};
