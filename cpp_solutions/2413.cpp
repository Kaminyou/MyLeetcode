class Solution {
public:
    int smallestEvenMultiple(int n) {
        if (n & 1) return n * 2;
        return n;
    }
};