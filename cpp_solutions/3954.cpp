class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int res = 0;
        for (int i = max(n - k, 1); i <= n + k; ++i) {
            if ((i & n) == 0) res += i;
        }
        return res;
    }
};
