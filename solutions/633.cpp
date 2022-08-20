class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long long i = 0; i * i <= c; ++i) {
            long long left = c - i * i;
            double sq = sqrt(left);
            if (sq == (long long)sq) return true;
        }
        return false;
    }
};