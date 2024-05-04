class Solution {
public:
    int smallestFactorization(int num) {
        if (num == 1) return 1;
        vector<int> counts(10, 0);
        for (int i = 9; i >= 2; --i) {
            while (num % i == 0) {
                counts[i]++;
                num /= i;
            }
        }
        if (num != 1) return 0;
        long long res = 0;
        for (int i = 2; i <= 9; ++i) {
            for (int j = 0; j < counts[i]; ++j) {
                res = res * 10 + i;
                if (res > INT_MAX) return 0;
            }
        }
        return res;
    }
};