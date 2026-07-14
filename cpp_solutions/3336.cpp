class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int M = *max_element(nums.begin(), nums.end());
        int mod = 1e9 + 7;
        vector<vector<int>> dp(M + 1, vector<int>(M + 1, 0));
        vector<vector<int>> tempDP(M + 1, vector<int>(M + 1, 0));
        dp[0][0] = 1;
        for (auto& num : nums) {
            // copy values
            for (int i = M; i >= 0; --i) {
                for (int j = M; j >= 0; --j) {
                    tempDP[i][j] = dp[i][j];
                }
            }
            // update
            for (int i = M; i >= 0; --i) {
                for (int j = M; j >= 0; --j) {
                    int i2 = __gcd(num, i);
                    int j2 = __gcd(num, j);
                    int v = dp[i][j];
                    tempDP[i2][j] = (tempDP[i2][j] + v) % mod;
                    tempDP[i][j2] = (tempDP[i][j2] + v) % mod;
                }
            }
            // copy back
            for (int i = M; i >= 0; --i) {
                for (int j = M; j >= 0; --j) {
                    dp[i][j] = tempDP[i][j];
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= M; ++i) {
            res += dp[i][i];
            res %= mod;
        }
        return res;
    }
};
