class Solution {
public:
    int res = 0;
    void backtracking(int n, int row, vector<bool>& cols, vector<bool>& diagonals, vector<bool>& antidiagonals) {
        if (n == row) {
            res++;
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (cols[col]) continue;
            if (diagonals[row - col + n - 1]) continue;
            if (antidiagonals[row + col]) continue;
            cols[col] = true;
            diagonals[row - col + n - 1] = true;
            antidiagonals[row + col] = true;
            backtracking(n, row + 1, cols, diagonals, antidiagonals);
            cols[col] = false;
            diagonals[row - col + n - 1] = false;
            antidiagonals[row + col] = false;
        }
    }
    int totalNQueens(int n) {
        vector<bool> cols(n, false);
        vector<bool> diagonals(n * 2 - 1, false);
        vector<bool> antidiagonals(n * 2 - 1, false);
        backtracking(n, 0, cols, diagonals, antidiagonals);
        return res;
    }
};