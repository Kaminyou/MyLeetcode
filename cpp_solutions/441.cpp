class Solution {
public:
    bool criteria(long long x, long long n) {
        return (1 + x) * x / 2 > n;
    }
    int arrangeCoins(int n) {
        long long left = 0;
        long long right = (long long)n + 1;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (criteria(mid, n)) right = mid;
            else left = mid + 1;
        }
        return left - 1;
    }
};