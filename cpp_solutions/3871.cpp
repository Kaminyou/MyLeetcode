class Solution {
public:
    int getLength(long long num) {
        int cnt = 0;
        while (num) {
            cnt++;
            num /= 10;
        }
        return cnt;
    }
    long long countCommas(long long n) {
        long long res = 0;
        int length = getLength(n);
        for (int i = 1; i < length; ++i) {
            res += ((i - 1) / 3) * (pow(10, i) - pow(10, i - 1));
        }
        res += ((length - 1) / 3) * (n - pow(10, length - 1) + 1);
        return res;
    }
};

