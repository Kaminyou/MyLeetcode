class Solution {
public:
    int minOperations(int n) {
        int operation = 0;
        for (int i = 0; i < 15; ++i) {
            if (__builtin_popcount(n + (1 << i)) < __builtin_popcount(n)) {
                operation++;
                n += (1 << i);
            }
        }
        return operation + __builtin_popcount(n);
    }
};