class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 0) return false;
        return __builtin_popcount(n) == 1;
    }
};
