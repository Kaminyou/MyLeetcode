class Solution {
public:
    bool success = false;
    bool isValid(vector<vector<char>>& board, int x, int y) {
        // row
        int mask = 0;
        for (int j = 0; j < 9; ++j) {
            if (board[x][j] == '.') continue;
            int num = 1 << (board[x][j] - '0');
            if (mask & num) return false;
            mask |= num;
        }
        // col
        mask = 0;
        for (int i = 0; i < 9; ++i) {
            if (board[i][y] == '.') continue;
            int num = 1 << (board[i][y] - '0');
            if (mask & num) return false;
            mask |= num;
        }
        // grid
        mask = 0;
        for (int i = x / 3 * 3; i < x / 3 * 3 + 3; ++i) {
            for (int j = y / 3 * 3; j < y / 3 * 3 + 3; ++j) {
                //cout << "i: " << i << " j: " << j << endl;
                if (board[i][j] == '.') continue;
                int num = 1 << (board[i][j] - '0');
                if (mask & num) return false;
                mask |= num;
            }
        }
        return true;
    }
    void _solve(vector<vector<char>>& board, int index, vector<vector<char>>& res) {
        if (index == 81) {
            res = board;
            return;
        }
        int x = index / 9;
        int y = index % 9;
        if (board[x][y] != '.') {
            _solve(board, index + 1, res);
        }
        else {
            for (int k = 1; k <= 9; ++k) {
                board[x][y] = k + '0';
                if (!isValid(board, x, y)) {
                    board[x][y] = '.';
                    continue;
                }
                _solve(board, index + 1, res);
                board[x][y] = '.';
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> res(9, vector<char>(9, '.'));
        _solve(board, 0, res);
        board = res;
    }
};
