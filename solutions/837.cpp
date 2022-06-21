class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        // dp[i]: win prob when has sum = i card on hand
        vector<double> dp(k + maxPts, 0.0);
        double sum = 0;
        // after k -1 (or start from k)
        // alice cannot get new card, so she win or lose
        // if sum <= n she win => prob = 1
        // else she lose => prob = 0
        for (int i = k; i < k + maxPts; ++i) {
            if (i <= n) dp[i] = 1;
            else dp[i] = 0;
            sum += dp[i];
        }
        // prob. of getting new card is equal
        for (int i = k - 1; i >= 0; --i) {
            dp[i] = sum / maxPts;
            sum += dp[i];
            sum -= dp[i + maxPts];
        }
        return dp[0];
    }
};