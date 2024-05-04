typedef long long LL;
class Solution {
public:
    int checkRecord(int n) {
        LL mod = 1e9 + 7;
        vector<vector<LL>> dp(3, vector<LL>(2, 0));
        vector<vector<LL>> dpTemp(3, vector<LL>(2, 0));
        dp[0][0] = 1; //P
        dp[1][0] = 1; //L
        dp[0][1] = 1; //A
        
        for (int i = 1; i < n; ++i) {
            dpTemp[0][0] = (dp[0][0] + dp[1][0] + dp[2][0]) % mod;
            dpTemp[1][0] = dp[0][0] % mod;
            dpTemp[2][0] = dp[1][0] % mod;
            
            dpTemp[0][1] = (dpTemp[0][0] + dp[0][1] + dp[1][1]  + dp[2][1]) % mod;
            dpTemp[1][1] = dp[0][1] % mod;
            dpTemp[2][1] = dp[1][1] % mod;
            dp = dpTemp;
        }
        
        LL res = 0;
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 2; ++k) {
                res += dp[j][k];
                res %= mod;
            } 
        }
        
        return res;
    }
};