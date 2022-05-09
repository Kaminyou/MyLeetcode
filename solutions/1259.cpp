class Solution {
public:
    int numberOfWays(int numPeople) {
        const long long mod = 1e9 + 7;
        vector<long long> dp(numPeople + 1, 0);
        dp[0] = 1;
        dp[2] = 1;
        for (int i = 4; i <= numPeople; i += 2) {
            for (int j = 0; j <= i - 2; j += 2) {
                dp[i] += (dp[j] * dp[i - j - 2]);
                dp[i] %= mod;
            }
        }
        return dp[numPeople];
    }
};