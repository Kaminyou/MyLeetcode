class Solution {
public:
    double recursive(double x, int n) {
        if (n == 0) return 1.0;
        double half = recursive(x, n / 2);
        if (n % 2 == 0) return half * half;
        else return half * half * x;
    }
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        return recursive(x, n);
    }
};