class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int mod = 1e9 + 7;
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {0, 0})); // score, # of paths
        dp[n - 1][n - 1] = {0, 1};
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (board[i][j] == 'S') continue;
                if (board[i][j] == 'X') {
                    dp[i][j] = {0, 0};
                    continue;
                }
                // find largest score
                int v = 0;
                int path = 0;
                if (i + 1 <= n - 1) {
                    v = max(v, dp[i + 1][j].first);
                }
                if (i + 1 <= n - 1 && j + 1 <= n - 1) {
                    v = max(v, dp[i + 1][j + 1].first);
                }
                if (j + 1 <= n - 1) {
                    v = max(v, dp[i][j + 1].first);
                }
                if (i + 1 <= n - 1 && dp[i + 1][j].first == v) {
                    path += dp[i + 1][j].second;
                    path %= mod;
                }
                if (i + 1 <= n - 1 && j + 1 <= n - 1 && dp[i + 1][j + 1].first == v) {
                    path += dp[i + 1][j + 1].second;
                    path %= mod;
                }
                if (j + 1 <= n - 1 && dp[i][j + 1].first == v) {
                    path += dp[i][j + 1].second;
                    path %= mod;
                }
                int curr = board[i][j] - '0';
                if (board[i][j] == 'E') curr = 0;
                if (path == 0) curr = 0;
                dp[i][j] = {v + curr, path};
            }
        }
        vector<int> res(2, 0);
        res[0] = dp[0][0].first;
        res[1] = dp[0][0].second;
        return res;
    }
};
