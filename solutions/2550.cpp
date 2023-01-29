class Solution {
public:
    long long power(long long x, long long y) {
        long long mod = 1e9 + 7;
        long long temp;
        if (y == 0)
            return 1;
        temp = power(x, y / 2);
        temp %= mod;
        if (y % 2 == 0)
            return (temp * temp) % mod;
        else
            return (x * temp * temp) % mod;
    }
    int monkeyMove(int n) {
        // 2 ^ n - 2
        long long mod = 1e9 + 7;
        long long pow = power(2, n);
        pow %= mod;
        pow -= 2;
        pow += mod;
        pow %= mod;
        return pow;
    }
};
