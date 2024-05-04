class Solution {
public:
    int M;
    int N;
    void moveDown(vector<vector<int>>& board) {
        for (int j = 0; j < N; ++j) {
            int slow = M - 1;
            for (int i = M - 1; i >= 0; --i) {
                if (board[i][j] != 0) {
                    board[slow][j] = board[i][j];
                    slow--;
                }
            }
            for (; slow >= 0; slow--) board[slow][j] = 0;
        }
    }
    bool extend(vector<vector<int>>& board, int x, int y) {
        bool isComplete = true;
        int num = abs(board[x][y]);
        // check down
        int down = x;
        while (down + 1 < M && abs(board[down + 1][y]) == num) down++;
        if (down - x + 1 >= 3) {
            isComplete = false;
            for (int i = x; i <= down; ++i) board[i][y] = -abs(board[i][y]);
        } 
        
        // check right
        int right = y;
        while (right + 1 < N && abs(board[x][right + 1]) == num) right++;
        if (right - y + 1 >= 3) {
            isComplete = false;
            for (int j = y; j <= right; ++j) board[x][j] = -abs(board[x][j]);
        } 
        return isComplete;
    }
    bool crash(vector<vector<int>>& board) {
        bool isComplete = true;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] == 0) continue;
                if (!extend(board, i, j)) isComplete = false;
            }
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] < 0) board[i][j] = 0;
            }
        }
        return isComplete;
    }
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        M = board.size();
        N = board[0].size();
        bool isComplete = false;
        while (!isComplete) {
            isComplete = crash(board);
            moveDown(board);
        }
        return board;
    }
};