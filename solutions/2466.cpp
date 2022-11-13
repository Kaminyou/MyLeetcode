class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        long long mod = 1e9 + 7;
        vector<long long> endWithZero(high + 1, 0);
        vector<long long> endWithOne(high + 1, 0);
        endWithZero[zero] = 1;
        endWithOne[one] = 1;
        long long res = 0;
        for (int i = 1; i <= high; ++i) {
            if (i - zero > 0) {
                endWithZero[i] = endWithZero[i - zero] + endWithOne[i - zero];
            }
            if (i - one > 0) {
                endWithOne[i] = endWithZero[i - one] + endWithOne[i - one];
            }
            endWithZero[i] %= mod;
            endWithOne[i] %= mod;
            if (i >= low && i <= high) {
                res += endWithZero[i];
                res += endWithOne[i];
                res %= mod;
            }
        }
        return res;
    }
};