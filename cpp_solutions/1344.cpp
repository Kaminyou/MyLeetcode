class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h = (double)hour * 30 + (double)minutes / 60 * 30;
        double m = minutes * 6;
        return min(abs(h - m), 360 - abs(h - m));
    }
};
