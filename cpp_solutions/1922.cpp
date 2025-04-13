class Solution {
public:
    int countGoodNumbers(long long n) {
        long long mod = 1e9 + 7;
        // 2 ^ k
        vector<long long> fac(51, 1);
        fac[1] = 20;
        for (int i = 2; i <= 50; ++i) {
            fac[i] = fac[i - 1] * fac[i - 1];
            fac[i] %= mod;
        }
        long long res = 1;
        if (n & 1) {
            res = 5;
            n -= 1;
        }
        vector<bool> bits(51, false);
        int index = 1;
        while (n) {
            if (n & 1) {
                bits[index] = true;
            }
            index++;
            n /= 2;
        }
        for (int i = 1; i <= 50; ++i) {
            if (bits[i]) res *= fac[i - 1];
            res %= mod;
        }
        return res;
    }
};

