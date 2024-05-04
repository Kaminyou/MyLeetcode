class Solution {
public:
    bool isPowerOfFour(int n) {
        bool isPowerOfTwo = (n > 0 && ((n & (n - 1)) == 0));
        bool atOddPosition = (n & 0xaaaaaaaa) == 0;
        return isPowerOfTwo && atOddPosition;
    }
};
