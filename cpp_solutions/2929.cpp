class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long res = 0;
        for (int i = 0; i <= limit; ++i) {
            long long minVal = max(0, n - i - limit);
            long long maxVal = min(limit, n - i);
            if (maxVal < minVal) continue;
            res += (maxVal - minVal + 1);
        }
        return res;
    }
};

