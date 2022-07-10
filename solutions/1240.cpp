class Solution {
public:
    vector<vector<int>> memo;
    int dp(int n, int m) {
        // n < m
        if (n > m) swap(n, m);
        if (n == 0) return 0;
        if (n == 1) return m;
        if (n == m) return 1;
        if (memo[n][m] != -1) return memo[n][m];
        
        // base case
        memo[n][m] = dp(m - n, n) + 1;
        
        // edge case
        for (int i = n - 1; i >= 1; --i) {
            for (int j = 1; j < n; ++j) {
                if (i + j < n) continue;
                if (i + j > m) break;
                int a = dp(n - i, m - j);
                int b = dp(m - i, n - j);
                int c = dp(i + j - n, m - i - j);
                memo[n][m] = min(memo[n][m], a + b + c + 2);
            }
        }
        return memo[n][m];
    }
    int tilingRectangle(int n, int m) {
        memo.resize(15, vector<int>(15, -1));
        return dp(n, m);
    }
};