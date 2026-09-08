class Solution {
public:
    int cnt(int num) {
        int digits = 0;
        while (num) {
            digits++;
            num /= 10;
        }
        return (digits - 1) / 3;
    }
    int countCommas(int n) {
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            res += cnt(i);
        }
        return res;
    }
};
