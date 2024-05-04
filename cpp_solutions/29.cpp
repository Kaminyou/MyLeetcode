class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        long long m = llabs(dividend);
        long long n = llabs(divisor);
        bool sign = ((dividend < 0) ^ (divisor < 0));
        if (n == 1) return sign ? -m : m;
        
        long long res = 0;
        while (m >= n) {
            long long t = n;
            long long p = 1;
            while (t << 1 < m) {
                t <<= 1;
                p <<= 1;
            }
            res += p;
            m -= t;
        }
        return sign ? -res : res;
    }
};