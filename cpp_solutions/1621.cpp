class Solution {
public:
    int numberOfSets(int n, int k) {
        vector<vector<long long>> dp0(n, vector<long long>(k + 1, 0)); // i is not the end
        vector<vector<long long>> dp1(n, vector<long long>(k + 1, 0)); // i is the end
        for (int i = 0; i < n; ++i) {
            dp0[i][0] = 1;
        }
        long long mod = 1e9 + 7;
        for (int j = 1; j <= k; ++j) {
            long long prefix0 = 0;
            long long prefix1 = 0;
            for (int i = 0; i < n; ++i) {
            
                dp1[i][j] = prefix1;
                dp0[i][j] = prefix0;

                dp1[i][j] %= mod;
                dp0[i][j] %= mod;

                prefix1 += dp0[i][j - 1] + dp1[i][j - 1];
                prefix0 += dp1[i][j];

                prefix1 %= mod;
                prefix0 %= mod;
            }
        }
        return (dp0[n - 1][k] + dp1[n - 1][k] + mod) % mod;
    }
};
