class Solution {
public:
    long long mod = 1e9 + 7;
    long long inv(long long a) {
        if (a == 1) return 1;
        return (mod - mod / a) * inv(mod % a) % mod;
    }
    int comb(int n, int k) {
        long long res = 1L;
        for (int i = 0; i < k; ++i) {
            res = res * (n - i) % mod;
            res = res * inv(i + 1) % mod;
        } 
        return (int)(res % mod);
    }
    int numberOfWays(int startPos, int endPos, int k) {
        int diff = endPos - startPos;
        if ((k + diff) & 1) return 0;
        int forward = (k + diff) / 2;
        int backward = (k - diff) / 2;
        if (backward < 0) return 0;
        return comb(k, min(forward, backward));
    }
};