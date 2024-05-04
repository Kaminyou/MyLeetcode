class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> rowSums(m, 0);
        vector<int> colSums(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rowSums[i] += mat[i][j];
                colSums[j] += mat[i][j];
            }
        }
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] && rowSums[i] == 1 && colSums[j] == 1) res++;
            }
        }
        return res;
    }
};
