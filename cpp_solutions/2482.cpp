class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> rowOnes(m, 0);
        vector<int> colOnes(n, 0);
        vector<int> rowZeros(m, 0);
        vector<int> colZeros(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    rowZeros[i]++;
                    colZeros[j]++;
                }
                else {
                    rowOnes[i]++;
                    colOnes[j]++;
                }
            }
        }
        vector<vector<int>> diff(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                diff[i][j] = rowOnes[i] + colOnes[j] - rowZeros[i] - colZeros[j];
            }
        }
        return diff;
    }
};