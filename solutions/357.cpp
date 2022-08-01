class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        if (n == 0) return dp[0];
        dp[1] = 9;
        if (n == 1) return dp[0] + dp[1];
        int multiply = 9;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] * multiply;
            multiply--;
        }
        int total = 0;
        for (int i = 0; i <= n; ++i) total += dp[i];
        return total;
    }
};
