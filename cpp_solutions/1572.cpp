class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += mat[i][i];
        }
        for (int i = 0; i < n; ++i) {
            sum += mat[i][n - 1 - i];
        }
        if (n & 1) {
            int idx = n / 2;
            sum -= mat[idx][idx];
        }
        return sum;
    }
};