class Solution {
public:
    long long flowerGame(int n, int m) {
        // [1..a] a <= n
        // [1..b] b <= m
        // a + b = odd
        long long res = 0;
        for (int i = 1; i <= n; ++i) {
            if (i & 1) {
                // b is even [2, ..., m]
                res += m / 2;
            }
            else {
                // b is odd [1, ..., m]
                res += (m - 1) / 2 + 1;
            }
        }
        return res;
    }
};

