class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((board[0][0] ^ board[i][0] ^ board[0][j] ^ board[i][j]) == 1) return -1;
            }
        }
        int rowSum = 0;
        int colSum = 0;
        int rowSwap = 0;
        int colSwap = 0;
        for (int i = 0; i < n; ++i) {
            rowSum += board[0][i];
            colSum += board[i][0];
            
            // assume 101010...
            if (board[i][0] == (i % 2)) rowSwap++;
            if (board[0][i] == (i % 2)) colSwap++;
        }
        
        if (rowSum != n / 2 && rowSum != (n + 1) / 2) return -1;
        if (colSum != n / 2 && colSum != (n + 1) / 2) return -1;
        
        if (n & 1) {
            if (rowSwap & 1) {
                rowSwap = n - rowSwap;
            }
            if (colSwap & 1) {
                colSwap = n - colSwap;
            }
        }
        else {
            rowSwap = min(rowSwap, n - rowSwap);
            colSwap = min(colSwap, n - colSwap);
        }
        return (rowSwap + colSwap) / 2;
    }
};