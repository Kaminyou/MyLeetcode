class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dpH[m + 1][n + 1];
        int dpV[m + 1][n + 1];
        int dpD1[m + 1][n + 1];
        int dpD2[m + 2][n + 2];
        for (int i = 0; i <= m; ++i) {
            dpH[i][0] = 0;
            dpV[i][0] = 0;
            dpD1[i][0] = 0;
            dpD2[i][0] = 0;
        }
        for (int j = 0; j <= n; ++j) {
            dpH[0][j] = 0;
            dpV[0][j] = 0;
            dpD1[0][j] = 0;
            dpD2[0][j] = 0;
            
        }
        for (int i = 0; i <= m + 1; ++i) dpD2[i][n + 1] = 0;
        for (int j = 0; j <= n + 1; ++j) dpD2[m + 1][j] = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dpH[i + 1][j + 1] = dpH[i + 1][j] + grid[i][j];
                dpV[i + 1][j + 1] = dpV[i][j + 1] + grid[i][j];
                dpD1[i + 1][j + 1] = dpD1[i][j] + grid[i][j];
            }
            for (int j = n - 1; j >= 0; --j) {
                dpD2[i + 1][j + 1] = dpD2[i][j + 2] + grid[i][j];
            }
        }

        int res = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 2; k <= min(m, n); ++k) {
                    if (i + k > m) break;
                    if (j + k > n) break;
                    bool okay = true;
                    int target = dpH[i + 1][j + 1 + k - 1] - dpH[i + 1][j];
                    int d1 = dpD1[i + k][j + k] - dpD1[i][j];
                    int d2 = dpD2[i + k][j + 1] - dpD2[i][j + k + 1];
                    if (d1 != target) okay = false;
                    if (d2 != target) okay = false;
                    if (okay) {
                        for (int t = 0; t < k; ++t) {
                            int h = dpH[i + 1 + t][j + 1 + k - 1] - dpH[i + 1 + t][j];
                            int w = dpV[i + 1 + k - 1][j + 1 + t] - dpV[i][j + 1 + t];
                            if (h != target) {
                                okay = false;
                                break;
                            }
                            if (w != target) {
                                okay = false;
                                break;
                            }
                        }
                    }
                    if (okay) res = max(res, k);
                }
            }
        }
        return res;
    }
};

