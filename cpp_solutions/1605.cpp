class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size();
        int n = colSum.size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int maxVal = min(rowSum[i], colSum[j]);
                res[i][j] = maxVal;
                rowSum[i] -= maxVal;
                colSum[j] -= maxVal;
            }
        }
        return res;
    }
};

