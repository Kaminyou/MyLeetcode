class Solution {
public:
    int lenOfBinary(int num) {
        int res = 0;
        while (num) {
            res++;
            num >>= 1;
        }
        return res;
    }
    int concatenatedBinary(int n) {
        long long mod = 1e9 + 7;
        long long res = 0;
        for (int i = 1; i <= n; ++i) {
            int length = lenOfBinary(i);
            res <<= length;
            res += i;
            res %= mod;
        }
        return res;
    }
};