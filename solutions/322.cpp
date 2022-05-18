class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX >> 1);
        dp[0] = 0;
        int n = coins.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= amount; j++) {
                if (j < coins[i]) continue;
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        if (dp[amount] == (INT_MAX >> 1)) return -1;
        return dp[amount];
    }
};