class Solution {
public:
    int mod = 1e9 + 7;
    int getSum(int x1, int x2, int y1, int y2, vector<vector<int>>& prefixSum) {
        // inclusive
        int a1 = prefixSum[x2][y2];
        int a2 = prefixSum[x2][y1];
        int a3 = prefixSum[x1][y2];
        int a4 = prefixSum[x1][y1];
        return a1 - a2 - a3 + a4;
    }
    int _ways(int x, int y, int m, int n, int k, vector<vector<int>>& prefixSum, vector<vector<vector<int>>>& memo) {
        if (memo[x][y][k] != -1) return memo[x][y][k];
        if (k == 0) {
            return getSum(x, m, y, n, prefixSum) > 0;
        }
        int count = 0;
        for (int i = x + 1; i < m; ++i) {
            if (getSum(x, i, y, n, prefixSum) > 0) {
                count += _ways(i, y, m, n, k - 1, prefixSum, memo);
                count %= mod;
            }
        }
        for (int j = y + 1; j < n; ++j) {
            if (getSum(x, m, y, j, prefixSum) > 0) {
                count += _ways(x, j, m, n, k - 1, prefixSum, memo);
                count %= mod;
            }
        }
        return memo[x][y][k] = count;
    }
    int ways(vector<string>& pizza, int k) {
        int m = pizza.size();
        int n = pizza[0].size();
        vector<vector<int>> prefixSum(m + 1, vector<int>(n + 1, 0));
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(k, -1)));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int cnt = 0;
                if (pizza[i - 1][j - 1] == 'A') cnt = 1;
                prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] + cnt - prefixSum[i - 1][j - 1];
            }
        }

        return _ways(0, 0, m, n, k - 1, prefixSum, memo);
    }
};
