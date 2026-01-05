class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long res = 0;
        int negCnt = 0;
        long long close = INT_MAX;
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                res += abs(matrix[i][j]);
                if (matrix[i][j] < 0) negCnt++;
                close = min(close, (long long)abs(matrix[i][j]));
            }
        }
        if (!(negCnt & 1)) return res;
        return res - 2 * close;
    }
};
