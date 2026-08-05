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
        return res % mod;
    }
    int countValidSequences(int n, int k) {
        long long all = comb(n - 1, n - k);
        if (!(n - k & 1)) {
            int t = (n - k) / 2;
            long long odd = comb(t + k - 1, t);
            all = (all - odd + mod) % mod;
        }
        return all % mod;
    }
};
// > 0
// x1 + 1 + x2 + + 1 ... + xk + 1 = n
// x1 + ... + xk = n - k
// H(k, n-k) = C(n - 1, n - k)

// odd
// 2x1 + 1 + 2x2 + 1, ... + 2xk + 1 = n
// 2x1 + 2x2 + ... = n - k
// x1 + ... + xk = (n - k) / 2 => n - k must be even
// H(k, (n-k)/2) = C((n - k) / 2 + k - 1, (n - k) / 2)


