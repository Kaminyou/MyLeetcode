class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            int prev = min(k, i + 1);
            int maxVal = 0;
            for (int j = 1; j <= prev; ++j) {
                maxVal = max(maxVal, arr[i + 1 - j]);
                dp[i + 1] = max(dp[i + 1], dp[i + 1 - j] + maxVal * j);
            }
        }
        return dp[n];
    }
};
