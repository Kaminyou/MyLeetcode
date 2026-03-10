class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        long long dp0[1001][1001]; // dp0[i][j]: i zeros + j ones end with 0
        long long dp1[1001][1001]; // dp1[i][j]: i zeros + j ones end with 1
        for (int i = 0; i <= 1000; ++i) {
            for (int j = 0; j <= 1000; ++j) {
                dp0[i][j] = 0;
                dp1[i][j] = 0;
            }
        }
        for (int i = 1; i <= min(zero, limit); ++i) dp0[i][0] = 1;
        for (int j = 1; j <= min(one, limit); ++j) dp1[0][j] = 1;

        long long mod = 1e9 + 7;
        int L = limit + 1;
        for (int i = 1; i <= zero; ++i) {
            for (int j = 1; j <= one; ++j) {
                dp0[i][j] = dp0[i - 1][j] + dp1[i - 1][j] - (i >= L ? dp1[i - L][j] : 0);
                dp1[i][j] = dp1[i][j - 1] + dp0[i][j - 1] - (j >= L ? dp0[i][j - L] : 0);
                dp0[i][j] += mod;
                dp1[i][j] += mod;
                dp0[i][j] %= mod;
                dp1[i][j] %= mod;
            }
        }
        return (dp0[zero][one] + dp1[zero][one]) % mod;
    }
};

