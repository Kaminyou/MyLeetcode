class Solution {
public:
    const int mod = 1e9 + 7;
    int dp(int n, int k, vector<vector<int>>& memo) {
        if (k == 0) return 0;
        if (n == k) return 1;
        if (k > n) return 0;
        if (memo[n][k] != -1) return memo[n][k];
        return memo[n][k] = (1L * dp(n - 1, k - 1, memo) + 1L * dp(n - 1, k, memo) * (n - 1)) % mod;
    }
    int rearrangeSticks(int n, int k) {
        vector<vector<int>> memo(n + 1, vector<int>(k + 1, -1));
        return dp(n, k, memo);
    }
};