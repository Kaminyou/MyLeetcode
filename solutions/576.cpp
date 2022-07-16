class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        vector<vector<long long>> dpTemp(m, vector<long long>(n, 0));
        
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        dp[startRow][startColumn] = 1;
        long long res = 0;
        long long mod = 1e9 + 7;
        for (int k = 0; k < maxMove; ++k) {
            for (int i = 0; i < m; ++i) {
                res += dp[i][0];
                res += dp[i][n - 1];
                res %= mod;
            }
            for (int j = 0; j < n; ++j) {
                res += dp[0][j];
                res += dp[m - 1][j];
                res %= mod;
            }
            
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    dpTemp[i][j] = 0;
                    for (auto& direction : directions) {
                        int nI = i + direction.first;
                        int nJ = j + direction.second;
                        if (nI < 0 || nI >= m || nJ < 0 || nJ >= n) continue;
                        dpTemp[i][j] += dp[nI][nJ];
                        dpTemp[i][j] %= mod;
                    }
                }
            }
            dp = dpTemp;
        }
        return res;
    }
};

// V1
// class Solution {
// public:
//     int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
//         vector<vector<int>> dp(m, vector<int>(n, 0));
//         dp[startRow][startColumn] = 1;
//         long long count = 0;
//         const long long mod = 1e9 + 7;
//         for (int k = 0; k < maxMove; k++) {
//             vector<vector<int>> temp(m, vector<int>(n, 0));
//             for (int i = 0; i < m; ++i) {
//                 for (int j = 0; j < n; ++j) {
//                     if (i == 0) count += dp[i][j];
//                     if (i == m - 1) count += dp[i][j] ;
//                     if (j == 0) count += dp[i][j];
//                     if (j == n - 1) count += dp[i][j];
//                     if (i > 0) temp[i][j] += dp[i - 1][j];
//                     temp[i][j] %= mod;
//                     if (i < m - 1) temp[i][j] += dp[i + 1][j];
//                     temp[i][j] %= mod;
//                     if (j > 0) temp[i][j] += dp[i][j - 1];
//                     temp[i][j] %= mod;
//                     if (j < n - 1) temp[i][j] += dp[i][j + 1];
//                     temp[i][j] %= mod;
//                     count %= mod;
//                 }
//             }
//             dp = temp;
//         }
//         return count % mod;
//     }
// };