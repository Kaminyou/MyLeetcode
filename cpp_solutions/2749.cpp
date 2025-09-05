class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        long long num1L = num1;
        long long num2L = num2;
        if (num2L > num1L) return -1;
        for (int i = 0; i <= 60; ++i) {
            int low = __builtin_popcountll(num1L);
            long long high = num1L;
            if (low <= i && i <= high) return i;
            num1L -= num2L;
        }
        return -1;
    }
};

