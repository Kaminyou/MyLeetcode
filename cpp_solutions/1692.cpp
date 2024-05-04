class Solution {
public:
    const long long mod = 1e9 + 7;
    int dp(int n, int k, vector<vector<long long>>& memo) {
        if (k == 0 || n == 0) return memo[n][k] = 0;
        if (k > n) return memo[n][k] = 0;
        if (k == n) return memo[n][k] = 1;
        if (memo[n][k] != -1) return memo[n][k];
        return memo[n][k] = (dp(n - 1, k - 1, memo) + dp(n - 1, k, memo) * (long long)k) % mod;
    }
    int waysToDistribute(int n, int k) {
        vector<vector<long long>> memo(n + 1, vector<long long>(k + 1, -1));
        return dp(n, k, memo);
    }
};