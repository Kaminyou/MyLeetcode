class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        vector<double> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int k = target; k >= 0; k--) {
                // mean # of head > # of coin
                // since i (coin) from 0 and k (head) from 1
                // i (coin) should + 1
                if (k > i + 1) continue; 
                if (k == 0) dp[k] = dp[k] * (1 - prob[i]);
                else dp[k] = dp[k] * (1 - prob[i]) + dp[k - 1] * prob[i];
            }
        }
        return dp[target];
    }
};