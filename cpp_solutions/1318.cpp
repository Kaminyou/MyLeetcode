class Solution {
public:
    int minFlips(int a, int b, int c) {
        int maxVal = max({a, b, c});
        int mask = 1;
        int shift = 0;
        int res = 0;
        while ((mask << shift) <= maxVal) {
            int aBit = (a & (mask << shift)) >> shift;
            int bBit = (b & (mask << shift)) >> shift;
            int cBit = (c & (mask << shift)) >> shift;
            if ((aBit | bBit) != cBit) {
                if (cBit == 0) res += (aBit + bBit);
                else res += 1;
            }
            shift++;
        }
        return res;
    }
};