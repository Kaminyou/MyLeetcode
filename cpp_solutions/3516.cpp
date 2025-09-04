class Solution {
public:
    int findClosest(int x, int y, int z) {
        x = abs(x - z);
        y = abs(y - z);
        if (x < y) return 1;
        if (x > y) return 2;
        return 0;
    }
};
