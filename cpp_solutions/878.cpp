class Solution {
public:
    int criteria(long long x, long long a, long long b, long long n) {
        long long lcm = a * b / __gcd(a, b);
        long long cnt = x / a + x / b - x / lcm;
        return cnt >= n;
    }
    int nthMagicalNumber(int n, int a, int b) {
        long long mod = 1e9 + 7;
        long long left = 1;
        long long right = LLONG_MAX;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (criteria(mid, a, b, n)) right = mid;
            else left = mid + 1;
        }
        return left % mod;
    }
};