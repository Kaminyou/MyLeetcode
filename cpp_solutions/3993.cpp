class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if (n == 1) return s;
        long long res = s;
        long long time1 = (n - 1) / 2;
        long long time2 = n - 1 - time1;
        long long max1 = (long long)s + time1 * m - time2 * 1;
        long long max2 = (long long)s - time1 * 1 + time2 * m;
        res = max(res, max1);
        res = max(res, max2);
        // time2 > time1
        res = max(res, max1 + 1);
        return res;
    }
};

