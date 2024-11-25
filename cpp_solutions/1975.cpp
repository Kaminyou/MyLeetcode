class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long res = 0;
        int close = INT_MAX;
        int cnt = 0;
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                res += abs(matrix[i][j]);
                if (matrix[i][j] < 0) cnt++;
                if (abs(matrix[i][j]) < close) close = abs(matrix[i][j]);
            }
        }
        if (!(cnt & 1)) return res;
        return res - close * 2;
    }
};

