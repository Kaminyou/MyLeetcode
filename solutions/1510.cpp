class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                if (dp[i - j * j] == false) dp[i] = true;
            }
        }
        return dp[n];
    }
};