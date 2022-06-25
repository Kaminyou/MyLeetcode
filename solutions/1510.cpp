class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);
        for (int i = 0; i <= n; ++i) {
            if (dp[i] == false) {
                for (int j = 1; j * j + i <= n + 1; ++j) {
                    dp[i + j * j] = true;
                }
            }
        }
        return dp[n];
    }
};