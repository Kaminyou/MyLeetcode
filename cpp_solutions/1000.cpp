class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if (n == 1) return 0;
        if ((stones.size() - 1) % (k - 1) != 0) return -1;
        if (k > n) return -1;
        vector<int> prefixSum(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + stones[i - 1];
        }
        // memo[i][j] => min cost to merge [i, j] to 1 stone
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int length = k; length <= n; ++length) {
            for (int start = 0; start + length <= n; ++start) {
                
                int end = start + length - 1;
                dp[start][end] = INT_MAX;
                for (int t = start; t < end; t += (k - 1)) {
                    dp[start][end] = min(dp[start][end], dp[start][t] + dp[t + 1][end]);
                }
                if ((end - start) % (k - 1) == 0) { 
                    dp[start][end] += prefixSum[end + 1] - prefixSum[start];
                }
            }
        }
        return dp[0][n - 1];
    }
};