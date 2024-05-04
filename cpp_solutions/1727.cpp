class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < m; ++j) {
                if (matrix[j][i] == 0) cnt = 0;
                matrix[j][i] = cnt + matrix[j][i];
                cnt = matrix[j][i];
            }
        }

        int res = 0;
        for (int i = 0; i < m; ++i) {
            sort(matrix[i].begin(), matrix[i].end(), greater<int>());
            for (int j = 0; j < n; ++j) {
                res = max(res, matrix[i][j] * (j + 1));
            }
        }
        return res;
    }
};

