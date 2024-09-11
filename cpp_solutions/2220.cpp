class Solution {
public:
    int minBitFlips(int start, int goal) {
        int diff = start ^ goal;
        return __builtin_popcount(diff);
    }
};
