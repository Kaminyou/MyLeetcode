class Solution {
public:
    long long mod = 1e9 + 7;
    long long inv(long long a) {
        if (a == 1) return 1;
        return (mod - mod / a) * inv(mod % a) % mod;
    }
    long long comb(int n, int k) {
        long long res = 1L;
        for (int i = 0; i < k; ++i) {
            res = res * (n - i) % mod;
            res = res * inv(i + 1) % mod;
        } 
        return (res % mod);
    }
    int countGoodArrays(int n, int m, int k) {
        // C(n - 1, k) * m * m^(n - k - 1)
        long long res = comb(n - 1, k);
        res *= m;
        res %= mod;
        for (int i = 0; i < n - k - 1; ++i) {
            res *= (m - 1);
            res %= mod;
        }
        return res % mod;
    }
};

