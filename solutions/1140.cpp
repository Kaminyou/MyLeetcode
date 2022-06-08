class Solution {
public:
    int dp(int i, int j, vector<vector<int>>& memo, vector<int>& prefix) {
        if (i + 2 * j >= prefix.size()) return prefix[i];
        if (memo[i][j] != -1) return memo[i][j];
        for (int k = 1; k <= 2 * j; ++k) {
            memo[i][j] = max(memo[i][j], prefix[i] - dp(i + k, max(k, j), memo, prefix));
        }
        return memo[i][j];
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> prefix = piles;
        vector<vector<int>> memo(n, vector<int>(n, -1));
        for (int i = n - 2; i >= 0; --i) {
            prefix[i] += prefix[i + 1];
        }
        return dp(0, 1, memo, prefix);
    }
};