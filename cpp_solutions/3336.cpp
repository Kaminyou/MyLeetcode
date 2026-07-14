class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int M = *max_element(nums.begin(), nums.end());
        int mod = 1e9 + 7;
        vector<vector<int>> dp(M + 1, vector<int>(M + 1, 0));
        dp[0][0] = 1;
        for (auto& num : nums) {
            vector<vector<int>> temp(M + 1, vector<int>(M + 1, 0));
            for (int i = M; i >= 0; --i) {
                for (int j = M; j >= 0; --j) {
                    int i2 = __gcd(num, i);
                    int j2 = __gcd(num, j);
                    int v = dp[i][j];
                    temp[i2][j] = (temp[i2][j] + v) % mod;
                    temp[i][j2] = (temp[i][j2] + v) % mod;
                    temp[i][j] = (temp[i][j] + v) % mod;
                }
            }
            dp = temp;
        }
        int res = 0;
        for (int i = 1; i <= M; ++i) {
            res += dp[i][i];
            res %= mod;
        }
        return res;
    }
};
