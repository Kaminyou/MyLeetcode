class Solution {
public:
    long long mod = 1e9 + 7;
    long long inv(long long a) {
        if (a == 1) return 1;
        return (mod - mod / a) * inv(mod % a) % mod;
    }
    int countOrders(int n) {
        long long res = 1;
        for (long long i = 1; i <= 2 * n; ++i) {
            res *= i;
            res %= mod;
            if (!(i & 1)) res *= inv(2);
            res %= mod;
        }
        return res;
    }
};
