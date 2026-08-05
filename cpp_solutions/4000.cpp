class Solution {
public:
    int largestInteger(int n, int s) {
        if (n * 9 < s) return -1;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int digit = min(s, 9);
            s -= digit;
            res *= 10;
            res += digit;
        }
        return res;
    }
};
