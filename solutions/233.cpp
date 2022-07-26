class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        for (long long m = 1; m <= n; m *= 10) {
            long long prefix = n / m;
            long long suffix = n % m;
            bool currentIsOne = (prefix % 10) == 1;
            res += (prefix + 8) / 10 * m;
            if (currentIsOne) res += 1 + suffix;
        }
        return res;
    }
};