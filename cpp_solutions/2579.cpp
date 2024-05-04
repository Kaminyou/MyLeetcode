class Solution {
public:
    long long coloredCells(int n) {
        long long res = 0;
        res += (long long)(n) * (long long)(n);
        res += (long long)(n - 1) * (long long)(n - 1);
        return res;
    }
};