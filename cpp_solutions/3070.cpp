class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> prefixSum(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                prefixSum[i + 1][j + 1] = grid[i][j] + prefixSum[i + 1][j] + prefixSum[i][j + 1] - prefixSum[i][j];
            }
        }

        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int curr = prefixSum[i + 1][j + 1] - prefixSum[1][0] - prefixSum[0][1] + prefixSum[0][0];
                if (curr <= k) res++;
                else break;
            }
        }
        return res;
    }
};
