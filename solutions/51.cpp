class Solution {
public:
    vector<vector<string>> res;
    void backtracking(int n, int row, vector<string>& matrix, vector<bool>& rows, vector<bool>& cols, vector<bool>& diagonal, vector<bool>& antidiagonal) {
        if (row == n) {
            res.push_back(matrix);
            return;
        }
        
        for (int j = 0; j < n; ++j) {
            if (matrix[row][j] == 'Q') continue;
            if (rows[row]) continue;
            if (cols[j]) continue;
            if (diagonal[row - j + n - 1]) continue;
            if (antidiagonal[row + j]) continue;
            matrix[row][j] = 'Q';
            rows[row] = true;
            cols[j] = true;
            diagonal[row - j + n - 1] = true;
            antidiagonal[row + j] = true;

            backtracking(n, row + 1, matrix, rows, cols, diagonal, antidiagonal);
            rows[row] = false;
            cols[j] = false;
            diagonal[row - j + n - 1] = false;
            antidiagonal[row + j] = false;
            matrix[row][j] = '.';
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> rows(n, false);
        vector<bool> cols(n, false);
        vector<bool> diagonal(n * 2 - 1, false);
        vector<bool> antidiagonal(n * 2 - 1, false);
        string temp(n, '.');
        vector<string> matrix;
        for (int i = 0; i < n; ++i) {
            matrix.push_back(temp);
        }
        backtracking(n, 0, matrix, rows, cols, diagonal, antidiagonal);
        return res;
    }
};