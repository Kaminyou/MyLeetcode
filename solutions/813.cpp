class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int K) {
        int n = nums.size();
        vector<double> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        vector<double> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            dp[i] = (prefixSum[i] - prefixSum[0]) / i;
        }
        
        for (int k = 2; k <= K; ++k) {
            vector<double> tempDp(n + 1, 0);
            for (int i = k; i <= n; ++i) {
                for (int j = k - 1; j < i; ++j) {
                    tempDp[i] = max(tempDp[i], dp[j] + (prefixSum[i] - prefixSum[j]) / (i - j));
                }
            }
            dp = tempDp;
        }
        return dp[n];
    }
};