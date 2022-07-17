typedef long long LL;
class Solution {
public:
    int knightDialer(int n) {
        LL mod = 1e9 + 7;
        vector<vector<LL>> dp(4, vector<LL>(3, 1));
        vector<vector<LL>> dpTemp(4, vector<LL>(3, 0));
        dp[3][0] = 0;
        dp[3][2] = 0;
        
        for (int i = 1; i < n; ++i) {
            dpTemp[0][0] = (mod + dp[1][2] + dp[2][1]) % mod;
            dpTemp[0][1] = (mod + dp[2][0] + dp[2][2]) % mod;
            dpTemp[0][2] = (mod + dp[1][0] + dp[2][1]) % mod;
            dpTemp[1][0] = (mod + dp[0][2] + dp[2][2] + dp[3][1]) % mod;
            dpTemp[1][1] = 0;
            dpTemp[1][2] = (mod + dp[0][0] + dp[2][0] + dp[3][1]) % mod;
            dpTemp[2][0] = (mod + dp[0][1] + dp[1][2]) % mod;
            dpTemp[2][1] = (mod + dp[0][0] + dp[0][2]) % mod;
            dpTemp[2][2] = (mod + dp[0][1] + dp[1][0]) % mod;
            dpTemp[3][1] = (mod + dp[1][0] + dp[1][2]) % mod;
            
            dp = dpTemp;
        }
        
        LL res = 0;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 3; ++j) {
                res += dp[i][j];
                res %= mod;
            }
        }
        return res;
    }
};