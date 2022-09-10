class Solution {
public:
    bool isPrime(int num) {
        if (num == 2 || num == 3 || num == 5 || num == 7 || num == 11 || num == 13 || num == 17 || num == 19 || num == 23) return true;
        return false;
    }
    int countPrimeSetBits(int left, int right) {
        int res = 0;
        for (int i = left; i <= right; ++i) {
            if (isPrime(__builtin_popcount(i))) res++;
        }
        return res;
    }
};