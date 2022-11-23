class Solution {
public:
    void fillFalse(vector<bool>& v) {
        for (int i = 0; i < 9; ++i) v[i] = false;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> hash(9, false);
        // check row
        for (int i = 0; i < 9; ++i) {
            fillFalse(hash);
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                if (hash[board[i][j] - '1']) return false;
                hash[board[i][j] - '1'] = true;
            }
        }
        // check col
        for (int j = 0; j < 9; ++j) {
            fillFalse(hash);
            for (int i = 0; i < 9; ++i) {
                if (board[i][j] == '.') continue;
                if (hash[board[i][j] - '1']) return false;
                hash[board[i][j] - '1'] = true;
            }
        }
        // check grid
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                fillFalse(hash);
                for (int a = 0; a < 3; ++a) {
                    for (int b = 0; b < 3; ++b) {
                        if (board[i + a][j + b] == '.') continue;
                        if (hash[board[i + a][j + b] - '1']) return false;
                        hash[board[i + a][j + b] - '1'] = true;
                    }
                }
            }
        }
        return true;
    }
};